
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class Calculator extends JFrame implements ActionListener
{
    static JFrame frame;
    static Panel panel1,panel2;
    static Button one,two,three,four,five,six,seven,eight,nine,zero;
    static Button decimal;
    static Button addition,subtraction,division,multiplication,equals;
    static boolean lastPressed=true;
    //True if string false if number
    static Button clear;
    static JTextField textField;
    static JLabel warningLabel;
    static String currentTextBox;

    
    private void variableAssignment()
    {
        frame = new JFrame("My calculator");

        panel1= new Panel();
        panel2 = new Panel();
        panel1.setLayout(new GridLayout(4,4));
        panel2.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        one=new Button("1");
        two = new Button("2");
        three = new Button("3");
        four = new Button("4");
        five = new Button("5");
        six= new Button("6");
        seven = new Button("7");
        eight = new Button("8");
        nine= new Button("9");
        zero = new Button("0");

        decimal = new Button(".");

        addition= new Button("+");
        subtraction = new Button("-");
        division = new Button("/");
        multiplication = new Button("*");
        equals= new Button("=");

        textField = new JTextField("",30);
        //CHECK IF THE TEXTFIELD LENGTH IS OK
        clear = new Button("clear");
        warningLabel = new JLabel("Can't choose an operator again!");

    }

    public void createGui()
    {
        variableAssignment();

        panel1.add(seven);
        panel1.add(eight);
        panel1.add(nine);
        panel1.add(addition);
        panel1.add(four);
        panel1.add(five);
        panel1.add(six);
        panel1.add(subtraction);
        panel1.add(one);
        panel1.add(two);
        panel1.add(three);
        panel1.add(multiplication);
        panel1.add(zero);
        panel1.add(decimal);
        panel1.add(equals);
        panel1.add(division);

        panel2.add(textField);
        panel2.add(clear);
        panel2.add(warningLabel);

        frame.add(panel1,BorderLayout.CENTER);
        frame.add(panel2,BorderLayout.SOUTH);
        frame.setSize(500,500);
        
        frame.setVisible(true);
    }

    public void addNumberActionListeners()
    {
        seven.addActionListener(this);
        eight.addActionListener(this);
        nine.addActionListener(this);
        four.addActionListener(this);
        five.addActionListener(this);
        six.addActionListener(this);
        one.addActionListener(this);
        two.addActionListener(this);
        three.addActionListener(this);
        zero.addActionListener(this);
        decimal.addActionListener(this);

    }

    void addOperatorActionListener()
    {
        Operator operatorListener = new Operator();
        addition.addActionListener(operatorListener);
        subtraction.addActionListener(operatorListener);
        division.addActionListener(operatorListener);
        multiplication.addActionListener(operatorListener);
        equals.addActionListener(operatorListener);
        clear.addActionListener(operatorListener);

    }

    public Calculator()
    {
        variableAssignment();
        createGui();
        addNumberActionListeners();
        addOperatorActionListener();
    }

    public void actionPerformed(ActionEvent e)
    {
        //Enter the method if a number is chosen
        //DEAL WITH THE 
        warningLabel.setText("");
        if(!Operator.chosen)
        {
            //If no operator is chosen 
            //append the number enterered
            textField.setText("");
            append(e);
            //then put the appended value in the textbox;
            textField.setText(currentTextBox);
            
        }
        else
        {
            //if there is a new operaotor
            //empty the text box
            textField.setText("");
            //empty the textboxValue
            currentTextBox=null;
            //append the new value to the textBox
            append(e);

            textField.setText(currentTextBox);
            //set the new value to be the textBox Value
            Operator.chosen=false;
            //set the operator to false
        }

    }

    public String setNumber(ActionEvent e)
    {
        if(e.getSource()==one)
        {
            return"1";
        }
        else if(e.getSource()==two){
            return"2";
        }
        else if(e.getSource()==three)
        {
            return"3";
        }
        else if(e.getSource()==four){
            return"4";
        }
        else if(e.getSource()==five)
        {
            return"5";
        }
        else if(e.getSource()==six){
            return"6";
        }
        else if(e.getSource()==seven)
        {
            return"7";
        }
        else if(e.getSource()==eight)
        {
            return"8";
        }
        else if(e.getSource()==nine)
        {
            return"9";
        }
        else if(e.getSource()==zero)
        {
            return"0";
        }
        else if(e.getSource()==decimal)
        {
            return".";

        }
        else
        {
            return "";
        }
    }

    void append(ActionEvent e)
    {
        if(currentTextBox==null)
        {
            currentTextBox=setNumber(e);
        }
        else
        {
            currentTextBox+=setNumber(e);
        }
    }

    public static void main(String[] args)
    {
        Calculator myCalculator = new Calculator();
    }

}
class Operator extends JFrame implements ActionListener
{
    static double total;
    static boolean chosen = false;

    static ActionEvent next;

    static void init()
    {
        total=0;
        next=null;

        chosen=false;
        Calculator.currentTextBox=null;
        Calculator.textField.setText("");

    }
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource()== Calculator.clear)
        {
            init();
        }
        else if(chosen==true|| Calculator.currentTextBox==null)
        {
            
            Calculator.warningLabel.setText("Can't choose an operator again!");
        }
        else
        {
            if(next==null)
            {
                //if there is no operator and
                //this is the first operator
                next=e;
                //set the source
                Calculator.textField.setText("");        
                total=Double.parseDouble(Calculator.currentTextBox);

                Calculator.currentTextBox=null;

                chosen=true;
            }
            else 
            {
                //If there is an operator value that is already present

                //Set the current operation to be the next one
                //empty the textbox

                total=determineCalculation(next);
                
                next=e;

                
                Calculator.textField.setText(""+total);
                Calculator.currentTextBox=null;

                chosen=true;
            }

        }
    }

    double determineCalculation(ActionEvent e)
    {
        double result=0;

        if(e.getSource()==Calculator.addition)
        {
            result= add(total,(Double.parseDouble(Calculator.currentTextBox))); 
        }
        else if(e.getSource()==Calculator.subtraction)
        {
            result=subtract(total,Double.parseDouble(Calculator.currentTextBox)); 
        }
        else if(e.getSource()==Calculator.multiplication)
        {
            result= multiply(total,(Double.parseDouble(Calculator.currentTextBox))); 
        }
        else if(e.getSource()==Calculator.division)
        {
            result= divide(total,(Double.parseDouble(Calculator.currentTextBox))); 
        }
        if((e.getSource()==Calculator.equals))
        {
            return total ;

        }
        return result;
    }

    public double add(double value1, double value2)
    {
        return (value1+value2);
    }

    public double subtract(double value1, double value2)
    {
        return (value1-value2);
    }

    public double divide(double value1,double value2)
    {
        if(value1==0)
        {
            return 0;
        }
        else
        {
            return (value1/value2);
        }
    }

    public double multiply(double value1,double value2)
    {
        return (value1*value2);
    }
    

}
