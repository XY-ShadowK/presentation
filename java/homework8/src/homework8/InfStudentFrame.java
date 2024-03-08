package homework8;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.TreeSet;

public class InfStudentFrame extends JFrame {
    public static String[] columnNames={"姓名","性别","院系","专业"};
    DefaultTableModel tableModel;
    JTable infTable;
    JButton back;
    public void setProperty(){
        this.setTitle("学生信息显示窗口");
        this.setSize(600,450);
        this.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(false);
    }
    public void addInfStudent(InfStudent infStudent){
        this.tableModel.addRow(infStudent.toStringArray());
    }
    public void addInfStudents(TreeSet<InfStudent> infStudents){
        for(InfStudent infStudent:infStudents)
            this.addInfStudent(infStudent);
    }
    public void removeAllInfStudents(){
        while(this.tableModel.getRowCount()>0)this.tableModel.removeRow(0);
    }
    public InfStudentFrame(){
        this.tableModel=new DefaultTableModel();
        for(int i=0;i<4;i++)this.tableModel.addColumn(columnNames[i]);
        this.infTable=new JTable(this.tableModel);
        JScrollPane tableScroll=new JScrollPane(this.infTable);
        this.back=new JButton("返回");
        this.back.setLayout(new FlowLayout(FlowLayout.CENTER,15,50));
        this.back.addActionListener(new MyButtonListener());
        this.add(tableScroll,BorderLayout.CENTER);
        this.add(this.back,BorderLayout.SOUTH);
        this.setProperty();
    }
}
