#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);

class INotifier {
public:
	
	virtual void Notify(const std::string& message) = 0;

};

class SmsNotifier : public INotifier {

	const std::string phone_number;

public:

	SmsNotifier(const std::string &phnum) : phone_number(phnum) {}

	void Notify(const std::string &message) override {
		SendSms(phone_number, message);
	}

};

class EmailNotifier : public INotifier {

	const std::string email;

public:

	EmailNotifier(const std::string &em) : email(em) { }

	void Notify(const std::string &message) override {
		SendEmail(email, message);
	}
};

// void Notify(INotifier& notifier, const string& message) {
//   notifier.Notify(message);
// }


// int main() {
//   SmsNotifier sms{"+7-495-777-77-77"};
//   EmailNotifier email{"na-derevnyu@dedushke.ru"};

//   Notify(sms, "I have White belt in C++");
//   Notify(email, "And want a Yellow one");
//   return 0;
// }
