package homework8;

import java.io.Serializable;

class InfStudent implements Serializable,Comparable<InfStudent>{
    public String name,college,major;
    public boolean gender;
    public String[] toStringArray(){
        String genderStr=gender?"男":"女";
        return new String[]{this.name,genderStr,this.college,this.major};
    }
    @Override
    public int compareTo(InfStudent infStudent) {
        if(!this.college.equals(infStudent.college))return this.college.compareTo(infStudent.college);
        else if(!this.major.equals(infStudent.major))return this.major.compareTo(infStudent.major);
        else if(!this.name.equals(infStudent.name))return this.name.compareTo(infStudent.name);
        else if(this.gender!=infStudent.gender)return this.gender?1:-1;
        return 0;
    }
    public InfStudent(String name, boolean gender, String college, String major) {
        this.name = name;
        this.gender = gender;
        this.college = college;
        this.major = major;
    }
    public InfStudent(InfStudent infStudent){
        this(infStudent.name, infStudent.gender, infStudent.college, infStudent.major);
    }
    public InfStudent(String[] infStr){
        this(infStr[0],infStr[1].equals("男"),infStr[2],infStr[3]);
    }
}
