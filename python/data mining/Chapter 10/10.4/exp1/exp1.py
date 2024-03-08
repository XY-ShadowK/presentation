class ItemCF:
    def __init__(self):
        self.user_reviews = {}
        self.items = set()
        self.similar_likes_items = {}
        self.similar_dislikes_items = {}
        self.item_likes = {}
        self.item_dislikes = {}
        self.similarity_like_items = {}
        self.similarity_dislike_items = {}
    def setup(self,user_reviews):
        self.user_reviews = user_reviews
    def add_dict(origin_dict,key,value):
        origin_dict[key] = origin_dict[key] + value if key in origin_dict else value
    def add_similar_num(similar_dict,store,stored,value):
        if store in similar_dict:
            ItemCF.add_dict(similar_dict[store],stored,value)
        else:
            similar_dict[store] = {stored:value}
    def set_similar(self,reviews_dict):
        items = list(reviews_dict.keys())
        reviews = list(reviews_dict.values())
        length = len(items)
        for i in range(length):
            if reviews[i] > 0:
                ItemCF.add_dict(self.item_likes,items[i],1)
            if reviews[i] < 0:
                ItemCF.add_dict(self.item_dislikes,items[i],1)
            for j in range(i + 1,length):
                self.items.add(items[i])
                store = sorted([items[i],items[j]])
                if reviews[i] > 0 and reviews[j] > 0:
                    ItemCF.add_similar_num(self.similar_likes_items,store[0],store[1],1.0)
                elif reviews[i] < 0 and reviews[j] < 0:
                    ItemCF.add_similar_num(self.similar_dislikes_items,store[0],store[1],1.0)
    def set_similar_reviews(self):
        for reviews in self.user_reviews.values():
            self.set_similar(reviews)
    def set_similarity_items(similar_items,similarity_items,item,item_sims):
        if item in similar_items:
            for similar_item in similar_items[item].keys():
                w = similar_items[item][similar_item] / ((item_sims[item] * item_sims[similar_item]) ** 0.5)
                ItemCF.add_similar_num(similarity_items,item,similar_item,w)
                ItemCF.add_similar_num(similarity_items,similar_item,item,w)
    def set_similarities(self):
        items = sorted(list(self.items))
        length = len(items)
        for i in range(length):
            item_i = items[i]
            ItemCF.set_similarity_items(self.similar_likes_items,self.similarity_like_items,item_i,self.item_likes)
            ItemCF.set_similarity_items(self.similar_dislikes_items,self.similarity_dislike_items,item_i,self.item_dislikes)
    def train(self):
        self.set_similar_reviews()
        self.set_similarities()
    def recommend(self,reviews):
        items = set(reviews.keys())
        likes = {}
        dislikes = {}
        combined_likes = {}
        for item in items:
            if reviews[item] > 0 and item in self.similarity_like_items:
                for it,w in self.similarity_like_items[item].items():
                    ItemCF.add_similar_num(likes,it,'no ratio: ',w)
                    ItemCF.add_similar_num(likes,it,'with ratio: ',w * reviews[item])
            if reviews[item] < 0 and item in self.similarity_dislike_items:
                for it,w in self.similarity_dislike_items[item].items():
                    ItemCF.add_similar_num(dislikes,it,'no ratio: ',w)
                    ItemCF.add_similar_num(dislikes,it,'with ratio: ',- w * reviews[item])
                    if it in likes:
                        ItemCF.add_dict(combined_likes,it,likes[it]['with ratio: '] + dislikes[it]['with ratio: '])
        for item in items:
            likes.pop(item,None)
            dislikes.pop(item,None)
            combined_likes.pop(item,None)
        return likes,dislikes,combined_likes

corresponds = [-1.5,-1.0,-0.5,0.0,0.5,1.0]
def normalize(x):
    # return (x - 3.0) / 2.0
    return corresponds[x]

def get_data(filename,encoding,preprocess):
    f = open(filename,'r',encoding=encoding)
    data = {}
    for line in f.readlines():
        lst = list(map(int,(line.strip('\n')).split('\t')))
        if lst[0] in data:
            # data[lst[0]][lst[1]] = data[lst[0]][lst[1]] + preprocess(lst[2]) if lst[1] in data[lst[0]] else preprocess(lst[2])
            ItemCF.add_dict(data[lst[0]],lst[1],preprocess(lst[2]))
        else:
            data[lst[0]] = {lst[1]:preprocess(lst[2])}
    f.close()
    return data

train_data = get_data('u1.base','utf-8',normalize)
test_data = get_data('u1.test','utf-8',normalize)

itemCF = ItemCF()
itemCF.setup(train_data)
itemCF.train()

file_output = open('recommend.txt','w')
for user_reviews in test_data.keys():
    likes,dislikes,combined_likes = itemCF.recommend(test_data[user_reviews])
    likes = sorted(likes.items(),key=lambda x: x[1]['no ratio: '],reverse=True)
    dislikes = sorted(dislikes.items(),key=lambda x: x[1]['no ratio: '])
    combined_likes = sorted(combined_likes.items(),key=lambda x: x[1],reverse=True)
    print('user id: ',user_reviews,'\nrecommend likes(5 in all): ',likes[:5],'\nrecommend dislikes(5 in all): ',dislikes[:5],'\nrecommend combined likes(5 in all): ',combined_likes[:5])
    print('user id: ',user_reviews,'\nrecommend likes: ',likes,'\nrecommend dislikes: ',dislikes,'\nrecommend combined likes: ',combined_likes,file=file_output)
file_output.close()