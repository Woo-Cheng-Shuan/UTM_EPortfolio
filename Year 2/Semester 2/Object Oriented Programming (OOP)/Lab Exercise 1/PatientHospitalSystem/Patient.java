package PatientHospitalSystem;

public class Patient{
    private String name;
    private String id;
    private double paymentAmount;

    // Constructor to initialize attributes
    public Patient(String n, String i, double p) {
        this.name = n;
        this.id = i;
        this.paymentAmount = p;
    }
    
    public void setname(String name){
        this.name = name;
    }

    public void setid(String id){
        this.id = id;
    }

    public void setpaymentAmount(double paymentAmount){
        this.paymentAmount = paymentAmount;
    }

    public String getname(){
        return name;
    }

    public String getid(){
        return id;
    }

    public double getpaymentAmount(){
        return paymentAmount;
    }

    // Method to update payment amount
    public void updatePayment(double amount) {
        this.paymentAmount = amount;
    }

    // Method to copy payment amount from another Patient object
    public void copyPaymentFrom(Patient other) {
        this.paymentAmount = other.paymentAmount;
    }

    // Method to return a string representation of the Patient object
    public String toString() {
        return "Patient ID: " + id + " , Name: " + name + " , Payment : RM " + paymentAmount;
    }

}