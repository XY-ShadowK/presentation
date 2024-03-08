package homework8;

import java.io.*;
import java.util.TreeSet;

public class Homework8 {
    public static File infFile= new File(".\\infstudnet.dat");
    public static TreeSet<InfStudent> infStudents=new TreeSet<InfStudent>();
    public static InputFrame inputFrame=new InputFrame();
    public static InfStudentFrame infStudentFrame=new InfStudentFrame();
    public static TreeSet<InfStudent> objectFileInput()throws IOException{
        TreeSet<InfStudent> infStus=new TreeSet<InfStudent>();
        try {
            FileInputStream fis = new FileInputStream(infFile);
            if(fis.available()!=0){
                ObjectInputStream in = new ObjectInputStream(fis);
                infStus =(TreeSet<InfStudent>)in.readObject();
            }
            fis.close();
        }catch(FileNotFoundException e){
            infFile.createNewFile();
        }catch(ClassNotFoundException e){
            e.printStackTrace();
            System.exit(-1);
        }
        return infStus;
    }
    public static void objectFileOutput(TreeSet<InfStudent> infStudents)throws IOException{
        FileOutputStream fos;
        try{
            fos=new FileOutputStream(infFile);
        }catch (FileNotFoundException e){
            infFile.createNewFile();
            fos=new FileOutputStream(infFile);
        }
        ObjectOutputStream out=new ObjectOutputStream(fos);
        out.writeObject(infStudents);
        fos.close();
    }
    public static void main(String[] args) {
        try {
            infStudents=new TreeSet<>(objectFileInput());
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}
