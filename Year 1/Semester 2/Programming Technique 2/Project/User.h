#ifndef USER_H
#define USER_H

//User class declaration
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