#ifndef ADMIN_H
#define ADMIN_H

// Admin class declaration
class Admin {
    
    private :
    	int id = 007;
		double rate[12]={0.00,0.01,0.03,0.08,0.14,0.21,0.24,0.245,0.25,0.26,0.28,0.30};
		double amount[12]={0.00,0.00,150.00,600.00,1800.00,4600.00,10900.00,46900.00,83650.00,133650.00,237650.00,517650.00};
		
    public:   		
        
        int getId(){return id;}
        
        void updateRate();
        
        void displayRate();
        
        friend class User;
};

class User{
	private :
  		double yearlyIncome, relief, taxableIncome, incomeTax, rebate, MTD;
  
	public:
	  	User(double, double, double, double, double, double);
	  	
	    void setYearlyIncome(double);
	    void setRelief(double);
	    void setTaxableIncome(double);
	    void setIncomeTax(double);
	    void setRebate(double);
	    void setMtd(double);
	    
	    double calcYearlyIncome();
	    double calcTotalRelief();
	    double calcTaxableIncome(double, double);
	    double calcIncomeTax(double,Admin&);
	    double calcRebate(double);
	    void calcFinal(double, double , double);
	    void displaySummary();
	    
	    friend class Admin;
};

#endif