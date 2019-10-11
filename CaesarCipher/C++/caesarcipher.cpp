using namespace std;
 
int main()
{
	char message[100], ch;
	int i, key, n;
  
  cout<< "Press 1 to encrypt the message"<<endl;
  cout<< "Press 2 to decrypt the message" <<endl;
  
	cin>>n;
  if(n == 1)
    {
    cout << "Enter a message to encrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;

    for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      if(ch >= 'a' && ch <= 'z'){
        ch = ch + key;

        if(ch > 'z'){
          ch = ch - 'z' + 'a' - 1;
        }

        message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
        ch = ch + key;

        if(ch > 'Z'){
          ch = ch - 'Z' + 'A' - 1;
        }

        message[i] = ch;
      }
    }

    cout << "Encrypted message: " << message;
    }
  else if(n == 2)
    {
    cout << "Enter a message to decrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;

    for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      if(ch >= 'a' && ch <= 'z'){
        ch = ch - key;

        if(ch < 'a'){
          ch = ch + 'z' - 'a' + 1;
        }

        message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
        ch = ch - key;

        if(ch > 'a'){
          ch = ch + 'Z' - 'A' + 1;
        }

        message[i] = ch;
      }
    }

    cout << "Decrypted message: " << message;
    }
  else
    {
    cout<< "Entered number neither 1 nor 2"<<endl;
    }
	return 0;
}
