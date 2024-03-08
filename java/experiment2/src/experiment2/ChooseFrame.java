package experiment2;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.SQLException;

public class ChooseFrame extends JFrame {
    public class LinePanel extends JPanel{
        public LinePanel(){
            this.setLayout(new FlowLayout(FlowLayout.CENTER,5,10));
        }
    }
    public static JLabel tipLabel=new JLabel("当前登录学生:");
    public static JLabel idCourseLabel=new JLabel("课程号:");
    public static String[] columnNames={"课程号","课程名","学分"};
    public String idStu;
    public JLabel nameStuLabel;
    public JButton chooseButton,queryButton;
    public JTextField idCourseText;
    public DefaultTableModel infCourseTableModel;
    public JTable infCourseTable;
    public ChooseFrame()throws SQLException {
        this.setLayout(new GridLayout(1,2));
        this.infCourseTableModel=new DefaultTableModel();
        for(int i=0;i<3;i++)this.infCourseTableModel.addColumn(columnNames[i]);
        this.infCourseTable=new JTable(this.infCourseTableModel);
        JScrollPane tableScroll=new JScrollPane(this.infCourseTable);
        Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_course");
        while(Experiment2.rset.next())
            this.infCourseTableModel.addRow(new String[]{Experiment2.rset.getString("id_course"),Experiment2.rset.getString("name"),Experiment2.rset.getString("point")});
        LinePanel lpTip=new LinePanel();
        this.nameStuLabel=new JLabel("stu");
        lpTip.add(tipLabel);
        lpTip.add(this.nameStuLabel);
        LinePanel lpIDCourse=new LinePanel();
        this.idCourseText=new JTextField(12);
        lpIDCourse.add(idCourseLabel);
        lpIDCourse.add(idCourseText);
        LinePanel lpChoose=new LinePanel(),lpQuery=new LinePanel();
        this.chooseButton=new JButton("选课");
        this.chooseButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getActionCommand().equals("选课")){
                    String idCourse=idCourseText.getText();
                    try{
                        Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_course WHERE id_course='"+idCourse+"'");
                        if(Experiment2.rset.isBeforeFirst()){
                            Experiment2.rset.next();
                            String nameCourse=Experiment2.rset.getString("name");
                            String point=Experiment2.rset.getString("point");
                            Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_chosen WHERE id_stu='"+idStu+"' AND id_course='"+idCourse+"'");
                            if(!Experiment2.rset.isBeforeFirst()){
                                Experiment2.statement.executeUpdate("INSERT inf_chosen(id_stu,id_course,name_course,point)VALUES('"+idStu+"','"+idCourse+"','"+nameCourse+"','"+point+"')");
                                JOptionPane.showMessageDialog(null, "选课成功!","提示",JOptionPane.PLAIN_MESSAGE);
                            }
                            else JOptionPane.showMessageDialog(null,"此课程已选择!","选课失败",JOptionPane.WARNING_MESSAGE);
                        }
                        else JOptionPane.showMessageDialog(null,"课程不存在!","选课失败",JOptionPane.WARNING_MESSAGE);
                    }catch (SQLException exc){
                        exc.printStackTrace();
                    }
                }
            }
        });
        this.queryButton=new JButton("查询选课结果");
        this.queryButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getActionCommand().equals("查询选课结果")){
                    try{
                        Experiment2.chooseFrame.setVisible(false);
                        Experiment2.queryFrame=new QueryFrame(idStu);
                    }catch (SQLException exc){
                        exc.printStackTrace();
                    }
                }
            }
        });
        lpChoose.add(this.chooseButton);
        lpQuery.add(this.queryButton);
        JPanel jpRight=new JPanel();
        jpRight.add(lpTip);
        jpRight.add(lpIDCourse);
        jpRight.add(lpChoose);
        jpRight.add(lpQuery);
        jpRight.setLayout(new GridLayout(4,1));
        this.add(tableScroll);
        this.add(jpRight);
        this.setTitle("操作窗口");
        this.setSize(600,450);
        this.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(false);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                Experiment2.loginFrame.idText.setText("");
                Experiment2.loginFrame.passwordText.setText("");
                Experiment2.loginFrame.setVisible(true);
            }
        });
    }
}
