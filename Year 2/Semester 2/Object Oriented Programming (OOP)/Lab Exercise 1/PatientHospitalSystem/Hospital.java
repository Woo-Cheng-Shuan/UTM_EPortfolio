package PatientHospitalSystem;

public class Hospital{
    public static void main(String[] args){
        // Create two Patient objects
        Patient patient1 = new Patient("Ali", "P001", 120.5);
        Patient patient2 = new Patient("Siti", "P002", 80.0);

        // Display original details
        System.out.println("Original Details: ");
        System.out.println(patient1.toString());
        System.out.println(patient2.toString());

        // Update payment for patient1 and copy payment from patient1 to patient2
        patient1.updatePayment(150.0);
        patient2.copyPaymentFrom(patient1);

        //Display updated details
        System.out.println("\nAfter changes: ");
        System.out.println(patient1.toString());
        System.out.println(patient2.toString());
    }
}