#include <time.h>
#include "container.h"

using namespace std;

int main() {
	int power = 16;

	srand((unsigned int)time(nullptr)); 

	RedBlackTree A(power, "A");
	A.printSet();
	//A.printitSeq();
	RedBlackTree B(power, "B");
	B.printSet();
	//B.printitSeq();
	RedBlackTree C(power, "C");
	C.printSet();
	//C.printitSeq();
	RedBlackTree D(power, "D");
	D.printSet();
	//D.printitSeq();
	RedBlackTree E(power, "E");
	E.printSet();
	//E.printitSeq();


	//(A ∪ B) \ C \ (D ∪ E)

	RedBlackTree o1("A OR B");
	A.OR(B, o1);
	o1.printSet();
	//o1.printitSeq();

	RedBlackTree o2("(A OR B) DIF C");
	o1.DIF(C, o2);
	o2.printSet();
	//o2.printitSeq();

	RedBlackTree o3("D OR E");
	D.OR(E, o3);
	o3.printSet();
	//o3.printitSeq();

	RedBlackTree o4("(A OR B) DIF C DIF (D OR E)");
	o2.DIF(o3, o4);
	o4.printSet();
	//o4.printitSeq();

	RedBlackTree t("Test", 'TEST');
	t.printSet();
	//t.printitSeq();

	RedBlackTree o5("A MERGE B");
	A.MERGE(B, o5);
	o5.printitSeq();
	//o5.printitSeq();

	RedBlackTree o6("A CONCAT Test");
	A.CONCAT(t, o6);
	o6.printitSeq();
	//o6.printSet();

	RedBlackTree o7("A MUL 4");
	t.MUL(4, o7);
	o7.printitSeq();
	//o7.printSet();

	cin.get();

	return 0;
}