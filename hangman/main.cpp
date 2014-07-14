#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;

const int NUM = 26;
const string word_list[NUM] = {
  "apiary", "beetle", "cereal", "danger", "ensign", "florid",
  "loaner", "namage", "nonce",  "onset",  "plaid",  "quilt" ,
  "remote", "stolid", "train",  "useful", "valid",  "whence",
  "xenon",  "yearn",  "zippy"
};

int main()
{
  using std::cout;
  using std::cin;
  using std::tolower;
  using std::endl;

  std::srand(std::time(0));
  char play;
  cout << "Will you play a word game? <y/n>";
  cin >> play;
  play = tolower(play);
  while (play == 'y')
    {
      string target = word_list[std::rand() % NUM];
      int length = target.size();
      string attempt(length, '-');
      string bad_chars;
      int guesses = 6;

      cout << "Guess my secret word. It has " << length
           << " letters, and you guess\n"
           << "one letter at a time. You get " << guesses
           << " wrong guesses." << endl;
      cout << "Your word: " << attempt << endl;
      while (guesses > 0 && attempt != target)
        {
          char letter;
          cout << "Guess a letter: ";
          cin >> letter;
          if (bad_chars.find(letter) != string::npos
              || attempt.find(letter) != string::npos)
            {
              cout << "You already guessed that. Try again.\n";
              continue;
            }
          int loc = target.find(letter);
          if (loc == string::npos)
            {
              cout << "Oh, bad guess!\n";
              --guesses;
              bad_chars += letter;
            }
          else
            {
              cout << "Good guess!\n";
              attempt[loc] = letter;
              loc = target.find(letter, loc + 1);
              while (loc != string::npos)
                {
                  attempt[loc] = letter;
                  loc = target.find(letter, loc + 1);
                }
            }
          cout << "Your word: " << attempt << endl;
          if (attempt != target)
            {
              if (bad_chars.size() > 0)
                cout << "Bad choices: " << bad_chars << endl;
              cout << guesses << " bad guesses left\n";
            }
        }
      if (guesses > 0)
        cout << "That's right!\n";
      else
        cout << "Sorry, the word is " << target << endl;
      cout << "Will you play another? <y/n>";
      cin >> play;
      play = tolower(play);
    }

  cout << "Bye.\n";

  return 0;
}













