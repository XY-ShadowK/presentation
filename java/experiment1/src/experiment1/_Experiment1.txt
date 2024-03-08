package experiment1;

import java.util.ArrayList;
import java.util.Scanner;

class Environment{
    public static final int ERROR_INT_VALUE=-1;
    public static final double ERROR_DOUBLE_VALUE=-1.00;
    public static final int INITIAL_INT_VALUE=0;
    public static final double INITIAL_DOUBLE_VALUE=0.00;
    public static final String EXIT_STR_VALUE="exit";
    public static final boolean IF_OVERCHOOSE=false;
    public static ArrayList<InfCourse> infCourse=new ArrayList<InfCourse>();
    public static ArrayList<InfStudent> infStudent=new ArrayList<InfStudent>();
}

class GlobalTools{
    public static boolean displayInfCourse(int t){
        if(Environment.infCourse.size()<t+1)return false;
        Environment.infCourse.get(t).displayInfCourse("|","\t|\t","\t|\t","\t|\t|\t","\t|\t|\t\t","/","\t\t|");
        return true;
    }
    public static boolean displayInfCourseList(){
        if(Environment.infCourse.isEmpty())return false;
        int size=Environment.infCourse.size();
        for(int i=0;i<size;i++)if(!displayInfCourse(i))return false;
        return true;
    }
    public static boolean displayInfStudent(String tidStudent){
        for(InfStudent tinfStudent:Environment.infStudent)if(tinfStudent.idEquals(tidStudent)){
            System.out.println("\n|\t学号\t\t|\t姓名\t\t|\t\t专业\t\t|\t|\t总学分\t|\t还需学分\t|");
            tinfStudent.displayInfStudent("|","\t|\t","\t|\t","\t|\t|\t","\t|\t","\t|");
            ArrayList<Integer>tcourseStudent=tinfStudent.getCourse();
            System.out.println("所选课程信息如下：");
            ScreenControl.formInfCourse();
            for(int i:tcourseStudent)if(!displayInfCourse(i))return false;
            return true;
        }
        return false;
    }
    public static boolean chooseCourse(String tidStudent,String tnumCourse){
        int t=Environment.INITIAL_INT_VALUE;
        double addCredits=Environment.ERROR_DOUBLE_VALUE;
        for(InfCourse tinfCourse:Environment.infCourse){
            if(tinfCourse.numequals(tnumCourse)){
                addCredits=tinfCourse.getCredits();
                break;
            }
            t++;
        }
        if(addCredits==Environment.ERROR_DOUBLE_VALUE)return false;
        for(InfStudent tinfStudent:Environment.infStudent)
            if(tinfStudent.idEquals(tidStudent)&&tinfStudent.ifAdd(t)&&Environment.infCourse.get(t).ifAdd())
                return tinfStudent.addCourse(t,addCredits)&&Environment.infCourse.get(t).addMember();
                //可能仍有其他错误，保留boolean返回值
        return false;
    }
}
class ScreenControl{
    public static void enter(){
        System.out.println("\n\n\n\n\n\n\n\n\n\n");
    }
    public static void pause(){
        System.out.println("请按回车以继续。");
        Scanner sc=new Scanner(System.in);
        String t_str=sc.nextLine();
    }
    public static void space(int n){
        for(int i=0;i<n;i++) System.out.printf(" ");
    }
    public static void formInfCourse(){
        System.out.println("|\t课程编号\t|\t课程名称\t|\t学分\t\t|\t|\t授课教师\t|\t|\t已选人数/课程容量\t|");
    }
}

class InfCourse{
    private final String numCourse,nameCourse,nameTeacher;
    private final double creditsCourse;
    private final int capacityCourse;
    private int numMember;
    /*
    private InfCourse nextInfCourse;
    private InfCourse getLastNode(){
        return this.nextInfCourse==null?this:this.nextInfCourse.getLastNode();
    }
    public boolean addNode(InfCourse tinfCourse){
        if(tinfCourse==null)return false;
        if(this.creditsCourse==Experiment1.ERROR_DOUBLE_VALUE&&this.capacityCourse==Experiment1.ERROR_DOUBLE_VALUE);
        else {
            InfCourse lastInfCourse=this.getLastNode();
            lastInfCourse.nextInfCourse=tinfCourse;
        }
        return true;
    }*/
    public boolean numequals(String tnumCourse){
        return this.numCourse.equals(tnumCourse);
    }
    public void displayInfCourse(String str1,String str2,String str3,String str4,String str5,String str6,String str7){
        System.out.println(str1+this.numCourse+(this.numCourse.length()>=8?"":"\t")+str2+this.nameCourse+str3+this.creditsCourse+(this.creditsCourse<10.00?"\t":"")+str4+this.nameTeacher+str5+this.numMember+str6+this.capacityCourse+(this.capacityCourse<100?"\t":"")+str7);
    }
    private boolean ifAddNum(int addNumMember){
//        if(this.numMember+addNumMember>this.capacityCourse&&(!Environment.IF_OVERCHOOSE))return false;
        return !(this.numMember+addNumMember>this.capacityCourse&&(!Environment.IF_OVERCHOOSE));
    }
    public boolean ifAdd(){
        return this.ifAddNum(1);
    }
    private boolean addNumMember(int addNumMember){
        if(!this.ifAddNum(addNumMember))return false;
        //冗余设计
        this.numMember+=addNumMember;
        return true;
    }
    public boolean addMember(){
        return this.addNumMember(1);
    }
    public double getCredits(){
        return this.creditsCourse;
    }
    InfCourse(String tnumCourse,String tnameCourse,String tnameTeacher,double tcreditsCourse,int tnumMember,int tcapacityCourse/*,InfCourse tnextInfCourse*/){
        this.numCourse=tnumCourse;
        this.nameCourse=tnameCourse;
        this.nameTeacher=tnameTeacher;
        //虽为字符串但为常量，直接引用不用new
        this.creditsCourse=tcreditsCourse;
        this.capacityCourse=tcapacityCourse;
//        this.nextInfCourse=tnextInfCourse;
        this.numMember=tnumMember;
    }
    InfCourse(InfCourse tinfCourse){
        this(tinfCourse.numCourse,tinfCourse.nameCourse,tinfCourse.nameTeacher,tinfCourse.creditsCourse,tinfCourse.numMember,tinfCourse.capacityCourse/*,tinfCourse.nextInfCourse*/);
    }
    InfCourse(String tnumCourse,String tnameCourse,String tnameTeacher,double tcreditsCourse,int tcapacityCourse){
        this(tnumCourse,tnameCourse,tnameTeacher,tcreditsCourse,Environment.INITIAL_INT_VALUE,tcapacityCourse/*,null*/);
    }
    InfCourse(){
        this(null,null,null,Environment.ERROR_DOUBLE_VALUE,Environment.ERROR_INT_VALUE);
    }
}

class InfStudent{
    private final String idStudent,nameStudent,majorStudent;
    private final double creditsNeed;
    private double creditsNow;
    /*
    class NodeCourse{
        InfCourse nodeCourseStudent;
        NodeCourse nextNodeCourse;
        NodeCourse(InfCourse tnodeCourseStudent,NodeCourse tnextNodeCourse){
            this.nodeCourseStudent=tnodeCourseStudent;
            this.nextNodeCourse=tnextNodeCourse;
        }
        NodeCourse(InfCourse tnodeCourseStudent){
            this(tnodeCourseStudent,null);
        }
        NodeCourse(){
            this(null,null);
        }
    }
    NodeCourse courseStudent;*/
    /*
    private LinkedList<InfCourse> courseStudent;
    public void addCourse(InfCourse tinfCourse){
        courseStudent.add(tinfCourse);
        creditsNow+=tinfCourse.getCredits();
    }*/
    private ArrayList<Integer> courseStudent;
    public boolean idEquals(String tidStudent){
        return this.idStudent.equals(tidStudent);
    }
    public void displayInfStudent(String str1,String str2,String str3,String str4,String str5,String str6){
        System.out.println(str1+this.idStudent+str2+this.nameStudent+str3+this.majorStudent+str4+this.creditsNow+(this.creditsNow<10.00?"\t":"")+str5+(this.creditsNeed-this.creditsNow)+(this.creditsNeed-this.creditsNow<10.00?"\t":"")+str6);
    }
    public boolean ifAdd(int t){
//        if(this.courseStudent.contains(t))return false;
        return !(this.courseStudent.contains(t));
    }
    public boolean addCourse(int t,double addCredits){
        if(!this.ifAdd(t))return false;
        //冗余设计
        if(this.courseStudent.add(t)){
            this.creditsNow+=addCredits;
            return true;
        }
        //保留boolean返回值以防止其他错误如内存溢出
        return false;
    }
    public ArrayList<Integer> getCourse() {
        return courseStudent;
    }
    InfStudent(String tidStudent,String tnameStudent,String tmajorStudent,double tcreditsNeed,double tcreditsNow,ArrayList<Integer> tcourseStudent){
        this.idStudent=tidStudent;
        this.nameStudent=tnameStudent;
        this.majorStudent=tmajorStudent;
        //虽是字符串但为常量，直接引用不用new
        this.creditsNeed=tcreditsNeed;
        this.creditsNow=tcreditsNow;
//        this.courseStudent=null;
//        this.courseStudent=new LinkedList<InfCourse>();
        this.courseStudent=tcourseStudent;
    }
    InfStudent(InfStudent tinfStudent){
        this(tinfStudent.idStudent,tinfStudent.nameStudent,tinfStudent.majorStudent,tinfStudent.creditsNeed,tinfStudent.creditsNow,tinfStudent.courseStudent);
    }
    InfStudent(String tidStudent,String tnameStudent,String tmajorStudent,double tcreditsNeed){
        this(tidStudent,tnameStudent,tmajorStudent,tcreditsNeed,Environment.INITIAL_DOUBLE_VALUE,new ArrayList<Integer>());
    }
    InfStudent(){
        this(null,null,null,Environment.ERROR_DOUBLE_VALUE);
    }
}

class Menu{
    private static void subMenu1(){
        System.out.println("接下来的每一行，请单行输入课程编号、课程名称、授课教师姓名、课程学分、课程容量（用空格隔开）以录入课程信息");
        System.out.println("请单行输入 exit 以退出课程信息录入");
        Scanner sc=new Scanner(System.in);
        String tnumCourse,tnameCourse,tnameTeacher;
        double tcreditsCourse;
        int tcapacityCourse;
        while(true){
            tnumCourse=sc.next();
            if(tnumCourse.equals(Environment.EXIT_STR_VALUE))return;
            tnameCourse=sc.next();
            tnameTeacher=sc.next();
            tcreditsCourse=sc.nextDouble();
            tcapacityCourse=sc.nextInt();
            Environment.infCourse.add(new InfCourse(tnumCourse,tnameCourse,tnameTeacher,tcreditsCourse,tcapacityCourse));
        }
    }
    private static void subMenu2(){
        System.out.println("接下来的每一行，请单行输入学生学号、学生姓名、学生专业、学生应选学分（用空格隔开）以录入课程信息");
        System.out.println("请单行输入 exit 以退出学生信息录入");
        Scanner sc=new Scanner(System.in);
        String tidStudent,tnameStudent,tmajorStudent;
        double tcreditsNeed;
        while(true){
            tidStudent=sc.next();
            if(tidStudent.equals(Environment.EXIT_STR_VALUE))return;
            tnameStudent=sc.next();
            tmajorStudent=sc.next();
            tcreditsNeed=sc.nextDouble();
            Environment.infStudent.add(new InfStudent(tidStudent,tnameStudent,tmajorStudent,tcreditsNeed));
        }
    }
    private static boolean subMenu3(){
        if(Environment.infCourse.isEmpty()){
            System.out.println("不存在课程信息！请先录入课程信息再选课。");
            return false;
        }
        ScreenControl.formInfCourse();
        if(!GlobalTools.displayInfCourseList()){
            System.out.println("读取课程信息失败！");
            return false;
        }
        System.out.println("\n请单行输入选课学生学号、所选课程编号（用空格隔开）以进行选课");
        System.out.println("请单行输入 exit 以退出选课");
        Scanner sc=new Scanner(System.in);
        String tidStudent,tnumCourse;
        tidStudent=sc.next();
        if(tidStudent.equals(Environment.EXIT_STR_VALUE))return false;
        tnumCourse=sc.next();
        if(GlobalTools.chooseCourse(tidStudent,tnumCourse)) System.out.println("选课成功！已为学号 "+tidStudent+" 添加课程编号 "+tnumCourse+" 的课程\n");
        else System.out.println("选课失败！错误的学号/课程编号（或该学生已选上此课程/此课程已选满且未开启超额选课）。\n");
        return true;
    }
    private static boolean subMenu4(){
        if(Environment.infStudent.isEmpty()){
            System.out.println("不存在学生信息！请先录入学生信息再选课。");
            return false;
        }
        System.out.println("\n请单行输入学生学号以进行信息查询");
        System.out.println("请单行输入 exit 以退出信息查询");
        Scanner sc=new Scanner(System.in);
        String tidStudent=sc.next();
        if(tidStudent.equals(Environment.EXIT_STR_VALUE))return false;
        if(!GlobalTools.displayInfStudent(tidStudent)) System.out.println("信息查询失败！错误的学号。");
        return true;
    }
    public static boolean mainMenu(){
        System.out.println("1.录入课程信息");
        System.out.println("2.录入学生信息");
        System.out.println("3.学生选课");
        System.out.println("4.查询");
        System.out.println("5.退出系统");
        System.out.println("请输入数字以使用对应功能\n");
        Scanner sc=new Scanner(System.in);
        byte t;
        t=sc.nextByte();
        switch (t){
            case 1 : {
                subMenu1();
                ScreenControl.enter();
                break;
            }
            case 2 : {
                subMenu2();
                ScreenControl.enter();
                break;
            }
            case 3 : {
                do;
                while(subMenu3());
                ScreenControl.enter();
                break;
            }
            case 4 : {
                do;
                while(subMenu4());
                ScreenControl.enter();
                break;
            }
            case 5 : {
                ScreenControl.enter();
                System.out.println("程序正在退出······");
                ScreenControl.pause();
                return false;
            }
            default : {
                System.out.println("输入错误，不在选项内！");
                ScreenControl.pause();
                ScreenControl.enter();
                break;
            }
        }
        return true;
    }
}

public class Experiment1 {
    public static void main(String[] args){
//        System.out.println("|\t课程编号\t|\t课程名称\t|\t学分\t|\t|\t授课教师\t|\t|\t已选人数\t|\t课程容量\t|");
//        for(int i=1;i<=100;i++) System.out.printf("%d",i%10);
//        ScreenControl.pause();
        do;
        while(Menu.mainMenu());
    }
}
