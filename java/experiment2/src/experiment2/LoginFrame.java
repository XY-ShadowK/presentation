package experiment2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class LoginFrame extends JFrame {
    public class LinePanel extends JPanel{
        public LinePanel(){
            this.setLayout(new FlowLayout(FlowLayout.CENTER,5,10));
        }
    }
    public static JLabel idLabel=new JLabel("学号:");
    public static JLabel passwordLabel=new JLabel("密码:");
    public JTextField idText;
    public JTextField passwordText;
    public JButton loginButton;
    public LoginFrame(){
        this.setLayout(new GridLayout(2,1));
        JPanel jpUp=new JPanel();
        LinePanel lpUp1=new LinePanel(),lpUp2=new LinePanel();
        this.idText=new JTextField(12);
        this.idText.setHorizontalAlignment(JTextField.LEFT);
        this.passwordText=new JTextField(16);
        this.passwordText.setHorizontalAlignment(JTextField.LEFT);
        lpUp1.add(idLabel);
        lpUp1.add(this.idText);
        lpUp2.add(passwordLabel);
        lpUp2.add(passwordText);
        jpUp.add(lpUp1);
        jpUp.add(lpUp2);
        jpUp.setLayout(new FlowLayout(FlowLayout.CENTER,50,10));
        JPanel jpDown=new JPanel();
        this.loginButton=new JButton("登录");
        this.loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                if(e.getActionCommand().equals("登录")){
                    String idStu=idText.getText();
                    String password=passwordText.getText();
                    try{
                        Experiment2.rset=Experiment2.statement.executeQuery("SELECT * FROM inf_stu WHERE id_stu='"+idStu+"' AND password_stu='"+password+"'");
                        if(Experiment2.rset.isBeforeFirst()){
                            JOptionPane.showMessageDialog(null,"登录成功!","提示",JOptionPane.PLAIN_MESSAGE);
                            Experiment2.loginFrame.setVisible(false);
                            Experiment2.chooseFrame.setVisible(true);
                            Experiment2.rset.next();
                            Experiment2.chooseFrame.nameStuLabel.setText(Experiment2.rset.getString("name"));
                            Experiment2.chooseFrame.idStu=idStu;
                        }
                        else JOptionPane.showMessageDialog(null,"学号或密码错误!","登录失败",JOptionPane.WARNING_MESSAGE);
                    }catch (SQLException exc){
                        exc.printStackTrace();
                    }
                }
            }
        });
        jpDown.add(this.loginButton);
        jpDown.setLayout(new FlowLayout(FlowLayout.CENTER,50,10));
        this.add(jpUp);
        this.add(jpDown);
        this.setTitle("登录窗口");
        this.setSize(300,225);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
