package homework8;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class InputFrame extends JFrame {
    public class LinePanel extends JPanel{
        public LinePanel(){
            this.setLayout(new FlowLayout(FlowLayout.CENTER,5,10));
        }
    }
    public static JLabel nameLabel=new JLabel("姓名:");
    public static JLabel genderLabel=new JLabel("性别");
    public static JLabel collegeLabel=new JLabel("院系");
    public static JLabel majorLabel=new JLabel("专业");
    public JTextField nameText;
    public ButtonGroup genderButton;
    public JRadioButton maleButton,femaleButton;
    public JComboBox<String> collegeCombo,majorCombo;
    public JButton ensureEnter,showInfStudent,exit;
    public void setProperty(){
        this.setTitle("信息录入窗口");
        this.setSize(600,450);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
    public void reSet(){
        this.nameText.setText("");
        this.maleButton.setSelected(true);
        this.collegeCombo.setSelectedIndex(3);

    }
    public JPanel setNorthPanel(){
        JPanel jpNorth=new JPanel();
        this.nameText=new JTextField(8);
        this.nameText.setHorizontalAlignment(JTextField.LEFT);
        this.genderButton=new ButtonGroup();
        this.maleButton =new JRadioButton("男",true);
        this.femaleButton=new JRadioButton("女");
        this.genderButton.add(this.maleButton);
        this.genderButton.add(this.femaleButton);
        LinePanel lpNorth1=new LinePanel(),lpNorth2=new LinePanel();
        lpNorth1.add(nameLabel);
        lpNorth1.add(this.nameText);
        lpNorth2.add(genderLabel);
        lpNorth2.add(this.maleButton);
        lpNorth2.add(this.femaleButton);
        jpNorth.add(lpNorth1);
        jpNorth.add(lpNorth2);
        jpNorth.setLayout(new FlowLayout(FlowLayout.CENTER,50,10));
        return jpNorth;
    }
    public JPanel setCenterPanel(){
        JPanel jpCenter=new JPanel();
        this.collegeCombo=new JComboBox<String>(new String[]{"光电信息与计算机工程学院","机械工程学院","出版印刷与艺术设计学院","请选择院系"});
        this.collegeCombo.setSelectedIndex(3);
        String[][] majors=new String[][]{
                {"光学工程","信息与信息处理","计算机科学与技术","软件工程","控制科学与工程"},
                {"机械制造及其自动化","机械设计及理论","车辆工程","电气工程"},
                {"产品设计","编辑出版学","视觉传达设计","包装工程","新媒体技术"},
                {"请先选择院系"}
        };
        this.majorCombo=new JComboBox<String>(majors[3]);
        this.collegeCombo.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if(e.getStateChange()==ItemEvent.SELECTED){
                    majorCombo.removeAllItems();
                    for(String str:majors[collegeCombo.getSelectedIndex()])
                        majorCombo.addItem(str);
                }
            }
        });
        LinePanel lpCenter1=new LinePanel(),lpCenter2=new LinePanel();
        lpCenter1.add(collegeLabel);
        lpCenter1.add(this.collegeCombo);
        lpCenter2.add(majorLabel);
        lpCenter2.add(this.majorCombo);
        jpCenter.add(lpCenter1);
        jpCenter.add(lpCenter2);
        jpCenter.setLayout(new FlowLayout(FlowLayout.CENTER,50,10));
        return jpCenter;
    }
    public JPanel setSouthPanel(){
        JPanel jpSouth=new JPanel();
        this.ensureEnter=new JButton("确定录入");
        this.ensureEnter.addActionListener(new MyButtonListener(this));
        this.showInfStudent=new JButton("查看所有学生");
        this.showInfStudent.addActionListener(new MyButtonListener());
        this.exit=new JButton("退出");
        this.exit.addActionListener(new MyButtonListener());
        jpSouth.add(this.ensureEnter);
        jpSouth.add(this.showInfStudent);
        jpSouth.add(this.exit);
        jpSouth.setLayout(new FlowLayout(FlowLayout.CENTER,50,10));
        return jpSouth;
    }
    public InputFrame(){
        this.setLayout(new GridLayout(3,1));
        this.add(this.setNorthPanel());
        this.add(this.setCenterPanel());
        this.add(this.setSouthPanel());
        this.setProperty();
    }
}
