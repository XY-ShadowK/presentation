package temp1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

class LibraryFrame extends JFrame{
    public String[] books;
    public JLabel tipLabel;
    public JTextField searchText;
    public JButton searchButton;
    public JTextArea showText;
    public LibraryFrame(String[] books){
        this.books=books;
        this.setLayout(new BorderLayout(5,10));
        this.setTitle("图书搜索");
        this.setSize(400,200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel jpUp=new JPanel();
        this.tipLabel=new JLabel("输入图书名称:");
        this.searchText=new JTextField(15);
        this.searchButton=new JButton("搜索");
        jpUp.setLayout(new FlowLayout(FlowLayout.CENTER,5,10));
        jpUp.add(this.tipLabel);
        jpUp.add(this.searchText);
        jpUp.add(this.searchButton);
        this.showText=new JTextArea(100,300);
        this.showText.setEditable(false);
        this.searchButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (e.getActionCommand().equals("搜索")) {
                    String search = searchText.getText();
                    String result = "";
                    for (String book : books) {
                        if (book.indexOf(search) != -1) result = result + book + "\n";
                    }
                    showText.setText(result);
                }
            }
        });
        this.add(jpUp,BorderLayout.NORTH);
        this.add(this.showText,BorderLayout.CENTER);
        this.setVisible(true);
    }
}
public class Temp1 {
    public static void main(String[] args) {
        LibraryFrame libraryFrame=new LibraryFrame(new String[]{"java","java1","java和c","c++","c/c++"});
    }
}