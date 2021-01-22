#include<iostream>
#include<string>

using namespace std;
//function headers
void check_dfa(int current_state, string mtoken);
bool isDelimiter(char ch);
bool isInteger(string str);
int keyword(string tempch);
bool recognizeOp(string mtoken);
int ident(string tempch);
bool checkvalidity(string moten);
bool verifier(int current_state, int current_index, string mCode);
void convertInstruction(string input);
int main() {
	string input = "kin e = 1 ;";//ye input hain jo jarha

	int i;
	for (i = 0; i < input.size(); i++) {//ye puri string ka size tk chalanay k lie hain loop k sare elements check hon
		string mtoken = "";//mtoken nam ki string initialize krarhe hain take eik eik token bnaskein
		while (input[i] != ' ' && i < input.length()) {//ye jb tk sapce na aye eik token bnata rhee
			mtoken += input[i]; i++;//i++ islie hain take elements agay chlein or puri array utilize hoske
		}
		if (isInteger(mtoken)) {
			cout << mtoken << " is an constant. and valid" << endl;
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
			}
			if (keyword(mtoken) == 1)
			{
				cout << mtoken << " is a keyword" << endl;
				if (checkvalidity(mtoken)) {
					cout << "its Valid." << endl;
				}
				else cout << "Its Invalid." << endl;

			}//agr keyword hoga to ye true hoga

//yahan else pr tmhara IDENTIFIER KA CODE AYEGA, sample code hai neche jo pehle sahi chalrha tha
			else if (ident(mtoken) == 1) {
				cout << mtoken << " is an identifier" << endl;
			}

			mtoken = "";

		}
	}

	convertInstruction(input);
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
	string keywords[5] = { "khile","kif","klse","kin","kloat" };//ye tmhare keywords hain array ka size brhao or keywords daldo
	int i, flag = 0;

	for (i = 0; i < 5; ++i) {//jitne keywords hain i< (utna size ) hoga jaisay k abhi 7 keywords hain
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



//Check DFA 1/2/2020



bool Check_DFA_INT(int pCurrentState, int pCurrentIndex, string pUserInput)
{

	if (pCurrentState == 0 && pUserInput[pCurrentIndex] == 'k')
	{
		return Check_DFA_INT(1, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 1 && pUserInput[pCurrentIndex] == 'i')
	{
		return Check_DFA_INT(2, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 2 && pUserInput[pCurrentIndex] == 'n')
	{
		if (pUserInput.size() == 3) {
			return true;
		}
		else {
			return false;
		}
	}
}


bool Check_DFA_KIF(int pCurrentState, int pCurrentIndex, string pUserInput)
{

	if (pCurrentState == 0 && pUserInput[pCurrentIndex] == 'k')
	{
		return Check_DFA_INT(1, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 1 && pUserInput[pCurrentIndex] == 'i')
	{
		return Check_DFA_INT(2, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 2 && pUserInput[pCurrentIndex] == 'f')
	{
		if (pUserInput.size() == 3) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Check_DFA_klse(int pCurrentState, int pCurrentIndex, string pUserInput)
{

	if (pCurrentState == 0 && pUserInput[pCurrentIndex] == 'k')
	{
		return Check_DFA_INT(1, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 1 && pUserInput[pCurrentIndex] == 'l')
	{
		return Check_DFA_INT(2, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 2 && pUserInput[pCurrentIndex] == 's')
	{
		return Check_DFA_INT(3, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 3 && pUserInput[pCurrentIndex] == 'e')
	{
		if (pUserInput.size() == 4) {
			return true;
		}
		else {
			return false;
		}
	}
}


bool Check_DFA_Khile(int pCurrentState, int pCurrentIndex, string pUserInput)
{

	if (pCurrentState == 0 && pUserInput[pCurrentIndex] == 'k')
	{
		return Check_DFA_INT(1, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 1 && pUserInput[pCurrentIndex] == 'h')
	{
		return Check_DFA_INT(2, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 2 && pUserInput[pCurrentIndex] == 'i')
	{
		return Check_DFA_INT(3, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 3 && pUserInput[pCurrentIndex] == 'l')
	{
		return Check_DFA_INT(4, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 4 && pUserInput[pCurrentIndex] == 'e')
	{
		if (pUserInput.size() == 5) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Check_DFA_Kloat(int pCurrentState, int pCurrentIndex, string pUserInput)
{

	if (pCurrentState == 0 && pUserInput[pCurrentIndex] == 'k')
	{
		return Check_DFA_INT(1, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 1 && pUserInput[pCurrentIndex] == 'l')
	{
		return Check_DFA_INT(2, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 2 && pUserInput[pCurrentIndex] == 'o')
	{
		return Check_DFA_INT(3, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 3 && pUserInput[pCurrentIndex] == 'a')
	{
		return Check_DFA_INT(4, pCurrentIndex + 1, pUserInput);
	}
	else if (pCurrentState == 4 && pUserInput[pCurrentIndex] == 't')
	{
		if (pUserInput.size() == 5) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool checkvalidity(string mtoken) {

	if (Check_DFA_INT(0, 0, mtoken)) return true;
	else if (Check_DFA_Kloat(0, 0, mtoken)) return true;
	else if (Check_DFA_Khile(0, 0, mtoken)) return true;
	else if (Check_DFA_klse(0, 0, mtoken)) return true;
	else if (Check_DFA_KIF(0, 0, mtoken)) return true;
	else return false;

}
//----------------------CFGs------------------------------------------------------------------------------
bool var_assign(int current_state, int current_index,string mCode)
{
	
	if (current_state == 0 && mCode[current_index] == 'k')
	{
		current_state = 1;
		return var_assign(current_state, current_index + 1,mCode);
	}
	else if (current_state == 1 && mCode[current_index] == 'i')
	{
		current_state = 2;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 2 && mCode[current_index] == 'n')
	{
		current_state = 3;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 3 && mCode[current_index] == ' ')
	{
		current_state = 4;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 4 && mCode[current_index] == 'e')
	{
		current_state = 5;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 5 && mCode[current_index] == ' ')
	{
		current_state = 6;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 6 && mCode[current_index] == '=')
	{
		current_state = 7;
		return var_assign(current_state, current_index + 1, mCode);
	}

	else if (current_state == 7 && mCode[current_index] == ' ')
	{
		current_state = 8;
		return var_assign(current_state, current_index + 1, mCode);
	}

	else if (current_state == 8 && mCode[current_index] == '1')
	{
		current_state = 9;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 9 && mCode[current_index] == ' ')
	{
		current_state = 10;
		return var_assign(current_state, current_index + 1, mCode);
	}
	else if (current_state == 10 && mCode[current_index] == ';')
	{
		cout << "expresion is valid \n" << mCode << endl;
		if (current_index != mCode.length()) {
			return false;
		}
		else {
			return true;
		}

	}


}

bool var_dec(int current_state, int current_index,string mCode)
{
	//int e;
	if (current_state == 0 && mCode[current_index] == 'k')
	{
		current_state = 1;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 1 && mCode[current_index] == 'i')
	{
		current_state = 2;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 2 && mCode[current_index] == 'n')
	{
		current_state = 3;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 3 && mCode[current_index] == ' ')
	{
		current_state = 4;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 4 && mCode[current_index] == 'e')
	{
		current_state = 5;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 5 && mCode[current_index] == ' ')
	{
		current_state = 6;
		return var_dec(current_state, current_index + 1, mCode);
	}
	else if (current_state == 6 && mCode[current_index] == ';')
	{
		//cout << "expresion is valid \n" << mCode << endl;
		if (current_index != mCode.length()) {
			return false;
		}
		else {
			return true;
		}

	}


}

bool addition(int current_state, int current_index,string mCode)
{
	//e=e+1 ;
	if (current_state == 0 && mCode[current_index] == 'e')
	{
		current_state = 1;
		return addition(current_state, current_index + 1, mCode);
	}
	else if (current_state == 1 && mCode[current_index] == '=')
	{
		current_state = 2;
		return addition(current_state, current_index + 1, mCode);
	}
	else if (current_state == 2 && mCode[current_index] == 'e')
	{
		current_state = 3;
		return addition(current_state, current_index + 1, mCode);
	}
	else if (current_state == 3 && mCode[current_index] == '+')
	{
		current_state = 4;
		return addition(current_state, current_index + 1, mCode);
	}
	else if (current_state == 4 && mCode[current_index] == '1')
	{
		current_state = 5;
		return addition(current_state, current_index + 1, mCode);
	}
	else if (current_state == 5 && mCode[current_index] == ';')
	{
		cout << "expresion is valid \n" << mCode << endl;
		if (current_index != mCode.length()) {
			return false;
		}
		else {
			return true;
		}

	}


}


bool isVaraibleassign(string s) {
	if (var_assign(0, 0,s) == true);
	return true;
}
bool isVaraibleDeclaration(string s) {
	if (var_dec(0, 0,s) == true);
	return true;
}


bool isVaraibleaddition(string s) {
	if(addition(0,0,s))
	return true;
}

void convertInstruction(string s) {
	int mTemp = 0;

	if (isVaraibleassign(s) == true) {
		cout << "mov T" << mTemp << " , " << s[6] << endl;
	}
	else if (isVaraibleDeclaration(s) == true) {
		cout << "li $T" << mTemp << " , " << " 0 " << endl;
	}
	else if (isVaraibleaddition(s) == true)
	{
		cout << " t" << mTemp << " = " << s[0] << " + " << s[4] << endl;
	}
}


