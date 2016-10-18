#ifndef PACKAGE_H
#define PACKAGE_H
class Package
{
public:
	Package(char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, float, float = 0.50);
	//constructor, default cost per ounce is $0.5
	virtual double calculateCost();//virtual function of calculate the cost
	void setsender(char *, char *, char *, char *, char *);//set sender's infromation
	void setrecipient(char *, char *, char *, char *, char *);//set recipient's information
	void setweight(float);//set package weight
	void setcostperounce(float);//set regular cost per ounce
	//get all of these information
	char *getsendername();
	char *getsenderaddress();
	char *getsendercity();
	char *getsenderstate();
	char *getsenderzipcode();
	char *getrecipientname();
	char *getrecipientaddress();
	char *getrecipientcity();
	char *getrecipientstate();
	char *getrecipientzipcode();
	float getweight();
	float getcostperounce();
	virtual char * type_name() ;//type name as regular delivery
	~Package();//destructor
private:

protected:
	//data members store all the information of package
	char *sender_name;
	char *sender_address;
	char *sender_city;
	char *sender_state;
	char *sender_ZIPcode;
	char *recipient_name;
	char *recipient_address;
	char *recipient_city;
	char *recipient_state;
	char *recipient_ZIPcode;
	float weight;
	float cost_per_ounce;
};
#endif
