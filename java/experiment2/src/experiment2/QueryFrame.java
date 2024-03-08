package experiment2;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class QueryFrame extends JFrame {
    public class LinePanel extends JPanel{
        public LinePanel(){
            this.setLayout(new FlowLayout(FlowLayout.CENTER,5,10));
        }
    }
    public static JLabel tipIDStuLabel=new JLabel("学号:");
    public static JLabel tipNameLabel=new JLabel("姓名:");
    public static JLabel tipMajorLabel=new JLabel("专业:");
    public static JLabel tipPointLabel=new JLabel("已选课程总学分:");
    public static String[] columnNames={"课程号","课程名","学分"};
    public JLabel idStuLabel,nameLabel,majorLabel,pointLabel;
    public DefaultTableModel chooseCourseTableModel;
    public JTable chooseCourseTable;
    public QueryFrame(String idStu)throws SQLException {
        LinePanel lpIDStu=new LinePanel();
        this.idStuLabel=new JLabel(idStu);
        lpIDStu.add(tipIDStuLabel);
        lpIDStu.add(this.idStuLabel);
        Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_stu WHERE id_stu="+idStu);
        Experiment2.rset.next();
        LinePanel lpName=new LinePanel();
        this.nameLabel=new JLabel(Experiment2.rset.getString("name"));
        lpName.add(tipNameLabel);
        lpName.add(this.nameLabel);
        LinePanel lpMajor=new LinePanel();
        this.majorLabel=new JLabel(Experiment2.rset.getString("major"));
        lpMajor.add(tipMajorLabel);
        lpMajor.add(this.majorLabel);
        Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_chosen WHERE id_stu='"+idStu+"'");
        LinePanel lpPoint=new LinePanel();
        int point=0;
        this.chooseCourseTableModel=new DefaultTableModel();
        for(int i=0;i<3;i++)this.chooseCourseTableModel.addColumn(columnNames[i]);
        this.chooseCourseTable=new JTable(this.chooseCourseTableModel);
        JScrollPane tableScroll=new JScrollPane(this.chooseCourseTable);
        while(Experiment2.rset.next()){
            this.chooseCourseTableModel.addRow(new String[]{Experiment2.rset.getString("id_course"),Experiment2.rset.getString("name_course"),Experiment2.rset.getString("point")});
            point+=Experiment2.rset.getInt("point");
        }
        this.pointLabel=new JLabel(String.valueOf(point));
        lpPoint.add(tipPointLabel);
        lpPoint.add(this.pointLabel);
        LinePanel lpUp=new LinePanel();
        lpUp.add(lpIDStu);
        lpUp.add(lpName);
        lpUp.add(lpMajor);
        lpUp.add(lpPoint);
        this.add(lpUp,BorderLayout.NORTH);
        this.add(tableScroll,BorderLayout.CENTER);
        this.setTitle("选课结果");
        this.setSize(600,450);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosed(WindowEvent e) {
                Experiment2.chooseFrame.setVisible(true);
            }
        });
    }
}
