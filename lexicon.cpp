// Implementation starter file for CSCI 60 Homework 3; due Sunday 1/29/23
// List any collaborators and write your name here

#include "lexicon.h"
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/* TODO: implement the other functions declared in lexicon.h here */
Lexicon::Lexicon(string filename)
{
  ifstream f(filename);
  string temp[200000];
  size_ = 0;

  if (f.is_open())  
    {
      for (int i = 0; i < CAPACITY; i++) 
      {
        f >> temp[i];
      }
      f.close(); 
    }

  int val = 0;
  for (int x = 0; x < CAPACITY; x++)
  {
    if (!(find(begin(data_), end(data_), temp[x]) != end(data_)))
    data_[val++] = temp[x];
  }

  for (int i = 0; i < CAPACITY; i++) 
  {
    if (data_[i] != "")
    size_++;
  }
}

bool Lexicon::contains(string word) const
{
  int i = 0;
  while (i < CAPACITY)
  {
    if (data_[i++] == word) 
    return true;
  }
  return false;
}

bool Lexicon::insert(string word)
{
  return data_[size_-1] == word;
}

bool Lexicon::remove(string word)
{
  int i = 0;
  while (i < CAPACITY)
  {
    if (data_[i++] == word) 
    return true;
  }
  return false;
}

Lexicon Lexicon::operator |(const Lexicon& rhs) const
{
  Lexicon l;
  int pos = 0;
  for (int i = 0; i < CAPACITY; i++)
  {
    l.data_[pos++] = data_[i];
  }
  for (int j = 0; j < CAPACITY; j++)
  {
    l.data_[pos++] = rhs[j];
  }
  return l;
}

Lexicon Lexicon::operator &(const Lexicon& rhs) const
{
  Lexicon l;
  int pos = 0;
  for (int i = 0; i < CAPACITY; i++)
  {
    if (rhs.contains(data_[i]))
    l.data_[pos++] = data_[i];
  }
  return l;
}

Lexicon Lexicon::operator ^(const Lexicon& rhs) const
{
  Lexicon l;
  int pos = 0;
  for (int i = 0; i < CAPACITY; i++)
  {
    if (!rhs.contains(data_[i]))
    l.data_[pos++] = data_[i];
  }
  for (int i = 0; i < CAPACITY; i++)
  {
    if (!contains(rhs[i]))
    l.data_[pos++] = rhs[i];
  }
  return l;
}

bool operator ==(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  while (i < lhs.CAPACITY)
  {
    if (lhs.size() != rhs.size()) {return false;}
    else if (!lhs.contains(rhs[i]))
    {return false;}
    else if (!rhs.contains(lhs[i])) {return false;}
    i++;
  }
  return true;
}

bool operator !=(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  while (i < lhs.CAPACITY)
  {
    if (lhs.size() != rhs.size()) {return true;}
    else if (!lhs.contains(rhs[i]))
    {return true;}
    else if (!rhs.contains(lhs[i])) {return true;}
    i++;
  }
  return false;
}

bool operator <=(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  while (i < lhs.CAPACITY)
  {
    if (!rhs.contains(lhs[i++]))
    {return false;}
  }
  return true;
}

bool operator <(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  if (lhs <= rhs)
  {
    while (i < lhs.CAPACITY)
    {
      if (!lhs.contains(rhs[i++])) {return true;}
    }
  }
}

bool operator >=(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  while (i < lhs.CAPACITY)
  {
    if (!lhs.contains(rhs[i++]))
    {return false;}
  }
  return true;
}

bool operator >(const Lexicon& lhs, const Lexicon& rhs)
{
  int i = 0;
  if (lhs >= rhs)
  {
    while (i < lhs.CAPACITY)
    {
      if (!rhs.contains(lhs[i++])) {return true;}
    }
  }
}

// Inserts contents of lex in out in order, separated by spaces
ostream& operator <<(ostream& out, const Lexicon& lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}








// Test program starter file for CSCI 60 Homework 3; due Sunday 1/29/23

#include <iostream>
#include "lexicon.h"

using namespace std;

void yourTestCode();
void foundingDocs();
void annaKarenina();

int main() {
  // use your own txt files and your own test code to test as you go
  yourTestCode();
  // use these tests and the provided txt files to check your output at the end
  foundingDocs();
  annaKarenina();
  return 0;
}


void yourTestCode() {
/*
  // write whatever you want in here!
  Lexicon l1 = Lexicon("wordsA.txt");
  Lexicon l2 = Lexicon("wordsB.txt");
  Lexicon l5 = Lexicon("wordsC.txt");
  Lexicon l6 = Lexicon("wordsD.txt");

  // if (l1.contains("word3"))
  // cout << "yes" << endl;
  // else cout << "no" << endl;

  // if (l1.insert("word9"))
  // cout << "yes" << endl;
  // else cout << "no" << endl;
  Lexicon l3 = (l1 & l2);
  // for (int i = 0; i < l3.CAPACITY; i++)
  // {
  //   cout << l3[i] << " ";
  // }
  // cout << endl;

  Lexicon l4 = (l1 | l2);
  for (int i = 0; i < l4.CAPACITY; i++)
  {
    cout << l4[i] << " ";
  }

  cout << endl;
  cout << l4.size();

  cout << endl;

  if (l1 == l5)
  cout << "equal" << endl;
  else cout << "not equal" << endl;

  if (l1 != l5)
  cout << "not equal" << endl;
  else cout << "equal" << endl;

  if (l1 != l2)
  cout << "not equal" << endl;
  else cout << "equal" << endl;

  if (l6 <= l5)
  cout << "all contained" << endl;
  else cout << "not all contained" << endl;

  if (l6 < l5)
  cout << "l5 < l6" << endl;
  else cout << "false: l5 < l6" << endl;

  if (l5 > l6)
  cout << "l5 > l6" << endl;
  else cout << "false: l5 > l6" << endl;
*/
}



// Constructs and uses lexicon objects to do some text analysis.
// Pre: Must have const.txt decl.txt preamble.txt prescramble.txt in directory.
void foundingDocs() {
  
  // construct two lexicons from files and report their sizes
  Lexicon constitution("const.txt");
  Lexicon declaration("decl.txt");
  size_t nConst = constitution.size(), nDecl = declaration.size();
  cout << "\nThe US Constitution contains " << nConst << " distinct words.\n";
  cout << "The Declaration of Independence contains " << nDecl
    << " distinct words.\n";

  // combine lexicons using set operatons
  Lexicon both = constitution & declaration;
  Lexicon either = constitution | declaration;
  Lexicon exactlyOne = constitution ^ declaration;
  size_t nCommon=both.size(), nTotal=either.size(), nDiff=exactlyOne.size();
  cout << "The two documents have " << nCommon << " words in common.\n";
  cout << "There are " << nDiff << " words in their symmetric difference.\n";
  if (nTotal!=nCommon+nDiff) {
    cout << "Does it make sense that there are " << nTotal
      << " words in the combined lexicon?\n";
  }
  cout << endl;

  // check subset relationships
  if (constitution<=declaration) {
    cout << "Are all Constitution words in the Declaration of Independence?\n";
  } else {
    cout << 100.0*nCommon/nConst
      << "% of Constitution words are in the Declaration of Independence.\n";
    string uncommonWord = exactlyOne[0];
    if (constitution.contains(uncommonWord)) {
      cout << "\"" << uncommonWord << "\" is one that is not.\n";
    }
  }

  if (constitution>=declaration) {
    cout << "Are all Declaration of Independence words in the Constitution?\n";
  } else {
    cout << 100.0*both.size()/nDecl
      << "% of Declaration of Independence words are in the Constitution.\n";
    string uncommonWord = exactlyOne[nDiff-1];
    if (declaration.contains(uncommonWord)) {
      cout << "\"" << uncommonWord << "\" is one that is not.\n";
    }
  }
  cout << endl;

  // check strict subset relationships
  Lexicon preamble("preamble.txt");
  if (preamble<constitution) {
    cout << "The Constitution's preamble contains " << 100.0*preamble.size()/nConst
      << "% of the distinct words \nin the Constitution and no others.\n";
  } else {
    cout << "How can the preamble contain words not in the full Constitution?\n";
  }
  if (constitution>preamble) {
    cout << "The strict subset relationship remains true if we flip\n"
      << "the operator and args even though it's a different function call.\n";
  } else {
    cout << "Flipping the operator and args shouldn't change the answer.\n";
  }
  cout << endl;

  // check equivalence after changing word order
  Lexicon prescramble("prescramble.txt");
  if (preamble==prescramble) {
    cout << "Scrambling the words of the preamble gives an equivalent lexicon,";
    if ((preamble | prescramble) != preamble) {
      cout << " but why would the union of these things be non equivalent?\n";
    } else {
      cout << "\nwhich is equivalent to the union of the two.\n";
    }
  } else {
    cout << "Whoops, scrambling words shouldn't break equivalence.\n";
  }
  cout << endl;
  
}

// Checks that construction for large text files reaches capacity without error.
// Pre: Must have const.txt decl.txt preamble.txt prescramble.txt in directory.
void annaKarenina() {
  ifstream file("anna_karenina.txt");
  string token;
  size_t nRead = 0;
  while (file >> token) nRead++;
  file.close();
  cout << "\nAnna Karenina is " << nRead << " words (with repetition).\n";

  Lexicon akLex("anna_karenina.txt");
  size_t n = akLex.size();
  if (n<Lexicon::CAPACITY) {
    cout << "It contains " << n << " distinct words.\n";
  } else {
    cout << "The number of distinct words reaches our class's capacity.\n\n";
  }
}
