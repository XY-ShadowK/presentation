package homework8;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class MyButtonListener implements ActionListener {
    InputFrame inputFrame;
    boolean enter;
    public MyButtonListener(InputFrame inputFrame){
        this.inputFrame=inputFrame;
        enter=true;
    }
    public MyButtonListener(){
        this.inputFrame=null;
        enter=false;
    }
    @Override
    public void actionPerformed(ActionEvent e){
        if(e.getActionCommand().equals("确定录入")){
            if(!enter)return;
            Homework8.infStudents.add(
                    new InfStudent(
                            inputFrame.nameText.getText(),
                            inputFrame.maleButton.isSelected(),
                            inputFrame.collegeCombo.getItemAt(inputFrame.collegeCombo.getSelectedIndex()),
                            inputFrame.majorCombo.getItemAt(inputFrame.majorCombo.getSelectedIndex())
                    )
            );
            inputFrame.reSet();
            return;
        }
        if(e.getActionCommand().equals("查看所有学生")){
            Homework8.infStudentFrame.removeAllInfStudents();
            Homework8.infStudentFrame.addInfStudents(Homework8.infStudents);
            Homework8.inputFrame.setVisible(false);
            Homework8.infStudentFrame.setVisible(true);
            return;
        }
        if(e.getActionCommand().equals("退出")){
            try{
                Homework8.objectFileOutput(Homework8.infStudents);
                Homework8.inputFrame.dispose();
                Homework8.infStudentFrame.dispose();
                System.exit(0);
            }catch (IOException exc){
                exc.printStackTrace();
            }
            return;
        }
        if(e.getActionCommand().equals("返回")){
            Homework8.infStudentFrame.setVisible(false);
            Homework8.inputFrame.setVisible(true);
        }
    }
}
