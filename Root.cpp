// Big numbers (n-bit) square root
// Stage 1 - 128b (4 word)
//
//
// Example 32b (1):
// In : 2326440277 = 1000 1010 1010 1010 1010 1001 0101 0101b
// Out: 48233      = 0000 0000 0000 0000 1011 1100 0110 1001b
//
// Example 32b (2):
// In : 2511054761 = 1001 0101 1010 1011 1010 0111 1010 1001b
// Out: 50110      = 0000 0000 0000 0000 1100 0011 1011 1110b
//
// Out^2 = 2511012100 -> ratio = 0,00001698927505~0,002%
//
//
//
// Algorighm "Search and check - Square root" for 128b numbers
//
// In : number[] (128b-4w)
// Out: result[] (square root of number)
//
//
// result = 0;
// one = 2^127;
//
// while (one > number)
//     one = one/4;
//
// while (one != 0)
// {
//     if ( number >= (result + one) )
//     {
//         number = number - (result + one);
//         result = result/2 + one;
//     }
//     else
//       result = result/2;
//     one = one/4;
// }
//
// Stage 2
// Transform function for 32b-words arguments.
// Invent and implement (inconvenient) way of verify.
//
// Stage 3
//
//=If first cells equal zero, then go to next cell.
//=Speed tests depend on argument size
//
// Stage 4
//
// Verify
//
//
// Stage 5
// Raport
//
//


jaki problem
jakie znanem metody
dlaczego ta metoda
czasy
listingi
wyniki eksperymentów (plot,table)
Ograniczenia
Weryfikacja wyników
założenia
wnioski
Źródła


#include "Root_lib.cpp"


uint32_t input[] = { 0,0,1,2434322 };
uint32_t input2[] = { 0,0,0,0 };
uint32_t result[] = { 0,0,0,0 };


uint32_t input128[4] = { 0 };
uint32_t result128[4] = { 0 };

uint32_t input256[8] = { 0 };
uint32_t result256[8] = { 0 };

uint32_t input512[16] = { 0 };
uint32_t result512[16] = { 0 };

uint32_t input1024[32] = { 0 };
uint32_t result1024[32] = { 0 };

uint32_t input2048[64] = { 0 };
uint32_t result2048[64] = { 0 };



std::fstream fs;


int numberOfTests = 100;




int main(int argc, char const *argv[])
{

  // randomizer_init();
  //
  //   autoTest(input128   ,result128  ,numberOfTests, 4 );
  //   autoTest(input256   ,result256  ,numberOfTests, 8 );
  //   autoTest(input512   ,result512  ,numberOfTests, 16);
  //   autoTest(input1024  ,result1024 ,numberOfTests, 32);
  //   autoTest(input2048  ,result2048 ,numberOfTests, 64);



  // randomizer(input2048,64);
  // printAsBit(input2048,cout,64);
  // root(input2048,result2048,64);
  // cout << endl;
  // printAsBit(result2048,cout,64);


  // printAsBit(input,cout,4);
  // root(input,result,4);
  // cout << endl;
  // printAsBit(result,cout,4);
  //
  // cout << endl;
  // cout << square("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000010010");
  // cout << endl;



  // fs.open ("test.txt", std::fstream::out);
  //
  // fs << " morfewgwegegrem ipsum";
  //
  // printAsBit(input, fs);
  //
  // fs.close();
///////////////////////////////////////////

  // result = root(input)
  // minus = (result-1)^2
  // plus = (result+1)^2
  //
  //
  // minus < input < plus

  //uint32_t input[] = { 243,2345,24324,2434322 };
uint32_t input[] = { 0,0,0,2434322 };
  uint32_t input2[] = { 0,0,0,0 };
  copy_(input, input2, 4);



  uint32_t plus[] = { 0,0,0,0 };
  uint32_t minus[] = { 0,0,0,0 };
  uint32_t once[] = { 0,0,0,1 };


  string sbufor = "";




  //cout << "\nResult: ";
  root(input,result,4);
  //printAsBit(result,cout,4);





  add_word(result,once,plus,4);
  string sresult = convert(plus, 4, sbufor);
  string ssquarePlus =  square(sresult);

  subtract_word(result,once,minus,4);
  sbufor="";
  sresult = convert(minus, 4, sbufor);
  string ssquareMinus =  square(sresult);

  sbufor="";
  sresult = convert(result, 4, sbufor);
  string ssquareResult =  square(sresult);




  //cout << endl << "Square-: " ;
  cout << endl << fillStringToFixedSize(ssquareMinus,4);
  //cout << "\nInput: ";
  //printAsBit(result,cout,4);
  cout << endl << fillStringToFixedSize(ssquareResult,4);
  //cout << endl << "Square+: ";
  cout << endl << fillStringToFixedSize(ssquarePlus,4);


  cout << endl;

	return 0;
}
