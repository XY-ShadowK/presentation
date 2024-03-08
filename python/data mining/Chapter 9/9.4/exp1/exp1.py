import pandas as pd

class Apriori:
    def __init__(self):
        self.df = pd.DataFrame()
        self.columns = []
        self.min_support = 0
        self.min_confidence = 0
        self.support = {}
        self.l1 = []
        self.l = []
        self.lk = []
        self.ck_support_f = []
    def setup(self,dataF,min_s):
        self.df = dataF
        self.columns = list(self.df.columns.values)
        self.min_support = min_s
    def get_l1(self):
        self.l1 = []
        for i in range(len(self.columns)):
            support_n = len(self.df.loc[self.df[self.columns[i]] == 1])
            support_f = support_n / self.df.shape[0]
            self.ck_support_f.append(support_f)
            if support_f >= self.min_support:
                self.l1.append({i})
                self.support[frozenset({i})] = support_n
    def get_ck(self,k):
        ck = set()
        for l1 in self.l1:
            for lk in self.lk:
                c = l1.union(lk)
                if len(c) == k:
                    ck.add(frozenset(c))
        lk_set = set(map(frozenset,self.lk))
        ck_list = []
        for c in ck:
            is_add = True
            for s in c:
                ckm1 = set(c.copy())
                ckm1.remove(s)
                if ckm1 not in lk_set:
                    is_add = False
                    break
            if is_add:
                ck_list.append(set(c))
        return ck_list
    def get_lk(self,ck):
        self.lk = []
        row_n = self.df.shape[0]
        for c in ck:
            lst = [0.0] * row_n
            for s in c:
                lst = [lst[i] + self.df.loc[i,self.columns[s]] for i in range(row_n)]
            lc = len(c)
            # print(c,lst)
            lst = [lst_e == lc for lst_e in lst]
            support_n = sum(lst)
            support_f = support_n / row_n
            if support_f >= self.min_support:
                self.lk.append(c)
                self.support[frozenset(c)] = support_n
    def get_subset(st,subset):
        for s in st:
            sub = set(st.copy())
            sub.discard(s)
            if sub not in subset and sub :
                subset.append(sub)
                if len(sub) > 1:
                    Apriori.get_subset(sub,subset)
    def get_col_set(self,st):
        col_set = list(st)
        col_set = [self.columns[s] for s in col_set]
        col_set = str(col_set)
        return col_set
    def get_rules(self,min_c):
        self.min_confidence = min_c
        rules = pd.DataFrame(columns = ['A','B','S','C'])
        for l in self.l:
            subset = []
            Apriori.get_subset(l,subset)
            for sub in subset:
                confidence = self.support[frozenset(l)] / self.support[frozenset(sub)]
                if confidence >= self.min_confidence:
                    rule = pd.DataFrame({'A':[self.get_col_set(sub)],'B':[self.get_col_set(l - sub)],'S':[self.support[frozenset(l)] / self.df.shape[0]],'C':[confidence]})
                    rules = pd.concat([rules,rule])
        rules = rules.reset_index(drop=True)
        return rules
    def apriori(self,min_c):
        k = 1
        self.get_l1()
        if len(self.l1) == 0:
            return
        self.l = self.l + self.l1
        self.lk = self.l1
        while(True):
            k = k + 1
            ck = self.get_ck(k)
            self.get_lk(ck)
            self.l = self.l + self.lk
            if len(self.lk) == 0:
                break
        return self.get_rules(min_c)

def test():
    df = pd.read_csv('test.csv')
    ap = Apriori()
    ap.setup(df,0.2)
    rule_test = ap.apriori(0.5)
    rule_test.to_csv('test_out.csv')

# test()

df = pd.read_csv('Income.csv')
df.drop(columns = 'Unnamed: 0',inplace = True)

print('数据集前五项:',list(df.columns.values)[0:5])

ap0_1 = Apriori()
ap0_2 = Apriori()
ap0_1.setup(df,0.1)
ap0_2.setup(df,0.2)
rule1 = ap0_1.apriori(0.5)
rule2 = ap0_1.get_rules(0.6)
rule3 = ap0_2.apriori(0.5)

rule1.to_csv('Income_rule1.csv')
rule2.to_csv('Income_rule2.csv')
rule3.to_csv('Income_rule3.csv')

for i in range(len(ap0_1.columns)):
    print('项：',ap0_1.columns[i],'支持度：',ap0_1.ck_support_f[i])

print('rule1 关联规则数：',rule1.shape[0])
print('rule2 关联规则数：',rule2.shape[0])
print('rule3 关联规则数：',rule3.shape[0])