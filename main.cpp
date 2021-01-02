//CC project of FSOCIETY
//including header files

#include<iostream>
#include<string>

using namespace std;
//function headers
bool isDelimiter(char ch);
bool isInteger(string str);
int keyword(string tempch);
bool recognizeOp(string mtoken);
int ident(string tempch);
int main() {
	string input = "]";//ye input hain jo jarha

	int i, k;
	for (i = 0; i < input.size(); i++) {//ye puri string ka size tk chalanay k lie hain loop k sare elements check hon
		string mtoken = "";//mtoken nam ki string initialize krarhe hain take eik eik token bnaskein
		while (input[i] != ' ' && i < input.length()) {//ye jb tk sapce na aye eik token bnata rhee
			mtoken += input[i]; i++;//i++ islie hain take elements agay chlein or puri array utilize hoske
		}
		if (isInteger(mtoken)) {
			cout << mtoken << " is an constant. " << endl;
		}

		else if (recognizeOp(mtoken))//operators nikalne k lie, output function mein he derha hai

		{
			continue; //yahan bs btayega k waqai opeartor tha to new token bnao, nhi to false hojayega or check krega keyword to nhi
		}

		else {//agr operator na ho to, phr keyword and ya identifier hai ye check hoga
			if (mtoken.size() == 1)
			{
				char ch = mtoken[0];

				if (isDelimiter(ch)) {
					cout << mtoken << "   it is demiliter: " << endl;
				}

				int j = 0;
				if (keyword(mtoken) == 1)
				{
					cout << mtoken << " is a keyword" << endl;
				}//agr keyword hoga to ye true hoga

	//yahan else pr tmhara IDENTIFIER KA CODE AYEGA, sample code hai neche jo pehle sahi chalrha tha
				else if (ident(mtoken) == 1) {
					cout << mtoken << " is an identifier" << endl;
				}

				mtoken = "";
			}
		}
	}
		return 0;
	}


	bool isInteger(string str)
	{
		int i, len = str.length();

		if (len == 0)

			return (false);

		for (i = 0; i < len; i++) {
			if (str[i] != '0' && str[i] != '1' && str[i] != '2'

				&& str[i] != '3' && str[i] != '4' && str[i] != '5'

				&& str[i] != '6' && str[i] != '7' && str[i] != '8'

				&& str[i] != '9' || (str[i] == '-' && i > 0))

				return (false);
		}

		return (true);
	}

	bool isDelimiter(char ch)//to find single brackets
	{
		if (ch == ' ' ||

			ch == '/' || ch == ',' || ch == ';' || ch == '>' ||

			ch == '<' || ch == '=' || ch == '(' || ch == ')' ||

			ch == '[' || ch == ']' || ch == '{' || ch == '}')

			return (true);

		return (false);
	}

	int keyword(string tempch) {//declaring default Keyword functions
		string keywords[7] = { "$tin","$bubble","$fi","$el","$od","$eliw","$fol" };//ye tmhare keywords hain array ka size brhao or keywords daldo
		int i, flag = 0;

		for (i = 0; i < 7; ++i) {//jitne keywords hain i< (utna size ) hoga jaisay k abhi 7 keywords hain
			if (keywords[i] == tempch) {
				flag = 1;
				break;
			}
		}

		return flag;
	}
	bool recognizeOp(string mtoken) {//operator check krne k lie mera function hai
		if (mtoken == "++") {
			cout << "++ is an operator " << endl; return true;
		}
		else 	if (mtoken == "==") {
			cout << "== is an operator " << endl; return true;
		}
		else if (mtoken == "+")
		{
			cout << "+ is an operator " << endl; return true;
		}//check if + or ++ exists;
		else if (mtoken == "-") {
			cout << "- is an operator " << endl; return true;
		}//check if - or -- exists;
		else if (mtoken == "%")
		{
			cout << "% is an operator " << endl; return true;
		}
		else if (mtoken == "/")
		{
			cout << "/ is an operator " << endl; return true;
		}
		else if (mtoken == "*") {
			cout << "* is an operator " << endl; return true;
		}
		else if (mtoken == "=") {
			cout << "= is an operator " << endl;  return true;
		}
		else return false;
	}

	int ident(string tempch) {
		int flag = 0;
		for (int i = 0; i < tempch.length(); ++i) {
			if (isalnum(tempch[i])) {
				flag = 1;
				break;
			}
		}

		return flag;
	}
