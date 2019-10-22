#include <bits/stdc++.h>
#define INPUT_SIZE 64
#define KEY_SIZE 64
#define ROUND_KEY_SIZE 48
using namespace std;

class DES
{
private:
    bitset<INPUT_SIZE> _input;             // Input to DES
    bitset<INPUT_SIZE> _output;            // Output of DES
    bitset<KEY_SIZE> DES_key;              // Key given to Rounf key generator
    bitset<ROUND_KEY_SIZE> round_keys[16]; // Array of round keys
    bool roundKeysPresent;
    int IP[INPUT_SIZE] =
        {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
        };
    int FP[INPUT_SIZE] =
        {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25
        };
    int P[INPUT_SIZE / 2] =
        {
            16, 7, 20, 21,
            29, 12, 28, 17,
            1, 15, 23, 26,
            5, 18, 31, 10,
            2, 8, 24, 14,
            32, 27, 3, 9,
            19, 13, 30, 6,
            22, 11, 4, 25
        };
    // S-boxes
    int S_boxes[8][4][16] = {
        {
            {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
            {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
            {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
            {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
        },
        {
            {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
            {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
            {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
        },
        {
            {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
        },
        {
           { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
            {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
           { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
            {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
        },
        {
            {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
            {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
            {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
            {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
        },
        {
            {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
            {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
        },
        {
            {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
        },
        {
            {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
        }

    };

    int ED[ROUND_KEY_SIZE] =
        {
            32, 1, 2, 3, 4, 5,
            4, 5, 6, 7, 8, 9,
            8, 9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1
        };

    int CP[56]=  
    {    57,49,41,33,25,17,9, 
        1,58,50,42,34,26,18, 
        10,2,59,51,43,35,27, 
        19,11,3,60,52,44,36,           
        63,55,47,39,31,23,15, 
        7,62,54,46,38,30,22, 
        14,6,61,53,45,37,29, 
        21,13,5,28,20,12,4 
    }; // For parity drop

    int CD[ROUND_KEY_SIZE]= 
	{ 14,17,11,24,1,5, 
		3,28,15,6,21,10, 
		23,19,12,4,26,8, 
		16,7,27,20,13,2, 
		41,52,31,37,47,55, 
		30,40,51,45,33,48, 
		44,49,39,56,34,53, 
		46,42,50,36,29,32 
	};


public:
    DES(bitset<INPUT_SIZE> &input, bitset<INPUT_SIZE> &DESkey, bool enc_dec);
    void generate_round_keys();
    void DES_Encryption();
    void DES_Decryption();
    void initialize_compression_D_boxes();
    bitset<ROUND_KEY_SIZE> get_compression(bitset<56> *in, int CD[]);
    bitset<INPUT_SIZE/2> DES_function(bitset<32> &R, bitset<ROUND_KEY_SIZE> &round_key);
    bitset<INPUT_SIZE> mixer(bitset<INPUT_SIZE> &input, bitset<ROUND_KEY_SIZE> &round_key);
    bitset<INPUT_SIZE> swapper(bitset<INPUT_SIZE> set);
    bitset<INPUT_SIZE> DES_Round(bitset<INPUT_SIZE> &round_input, bitset<ROUND_KEY_SIZE> &round_key, int round_number);
    void apply_permutation(bitset<INPUT_SIZE> &input, int permutation[]);
    void apply_permutation(bitset<32> &input, int permutation[]);
    bitset<ROUND_KEY_SIZE> apply_expansion_permutation(bitset<32> &input, int expansion_permutation[]);
    bitset<ROUND_KEY_SIZE> get_expansion(bitset<INPUT_SIZE / 2> &input);
    bitset<4> get_substitution(bitset<6>& input, int S_box[][16]);
    void setRoundKeysPresent(bool b) {
        roundKeysPresent = b;
    }
};
DES::DES(bitset<INPUT_SIZE> &input, bitset<INPUT_SIZE> &DESkey, bool enc_dec)
{
    roundKeysPresent = false;
    if (enc_dec == true)
    {
        // Encryption mode
        this->_input = input;
        this->DES_key = DESkey;
        this->DES_Encryption();
    }
    else
    {
        // Decryption mode
        this->_output = input;
        this->DES_key = DESkey;
        this->DES_Decryption();
    }
}
// Apply permutation to 64 bit bitset
void DES::apply_permutation(bitset<INPUT_SIZE> &input, int permutation[])
{
    bitset<INPUT_SIZE> temp;
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        temp[INPUT_SIZE-1-i] = input[INPUT_SIZE-1-(permutation[i]-1)];
    }
    input = temp;
}

// Apply permutation to 32 bit bitset
void DES::apply_permutation(bitset<32>& input, int permutation[])
{
    bitset<32> temp;
    for(int i = 0; i < 32; i++){
        temp[31-i] = input[31-(permutation[i]-1)];
    }
    input = temp;
}

bitset<ROUND_KEY_SIZE> DES::apply_expansion_permutation(bitset<32> &input, int expansion_permutation[])
{
    // Modification
    bitset<ROUND_KEY_SIZE> output;
    for(int i = 0; i < ROUND_KEY_SIZE; i++)
    {
        output[ROUND_KEY_SIZE-1-i] = input[((INPUT_SIZE / 2)-1)-(expansion_permutation[i]-1)];
    } 
    return output; 
}


bitset<INPUT_SIZE> DES::DES_Round(bitset<INPUT_SIZE> &round_input, bitset<ROUND_KEY_SIZE> &round_key, int round_number)
{
    bitset<INPUT_SIZE> output;
    output = mixer(round_input, round_key);
    bitset<INPUT_SIZE> swapped;
    if (round_number != 16)
    {
        swapped = swapper(output);
        return swapped;
    }
    else
    {
        return output;
    }
    
}

void DES::DES_Encryption()
{
    
    if(roundKeysPresent == false){
        generate_round_keys();
        roundKeysPresent = true;
    }
    // Initial Permutation
    apply_permutation(_input, IP);
    bitset<INPUT_SIZE> out;
    bitset<INPUT_SIZE> in = _input;

    for (int i = 0; i < 16; i++)
    {
        // DES Rounds
        out = DES_Round(in, round_keys[i], i + 1);

        in = out;
    }
    // Final Permutation
    apply_permutation(out, FP);
    cout << out.to_string() << endl;
    _output = out;
}

void DES::DES_Decryption()
{
    if(roundKeysPresent == false){
        generate_round_keys();
        roundKeysPresent = true;
    }
    apply_permutation(_output, IP);
    bitset<INPUT_SIZE> out;
    bitset<INPUT_SIZE> in = _output;
    for(int i = 0; i < 16; i++)
    {
        out = DES_Round(in, round_keys[16-i-1], i+1);
        in = out;
    }
    apply_permutation(out, FP);
    cout << out.to_string() << endl;
    _input = out; 
}

bitset<ROUND_KEY_SIZE> DES::get_compression(bitset<56> *in, int CD[])
{
    bitset<ROUND_KEY_SIZE> out;
    for(int i = 0; i < 48; i++)
    {
        out[ROUND_KEY_SIZE-1-i] = (*in)[55 - (CD[i]-1)];
    }
    return out;
}

bitset<ROUND_KEY_SIZE> DES::get_expansion(bitset<INPUT_SIZE / 2> &input)
{
    bitset<ROUND_KEY_SIZE> output;
    output = apply_expansion_permutation(input, ED);
    return output;
}

bitset<4> DES::get_substitution(bitset<6>& input, int S_box[][16])
{
    bitset<2> row;
    bitset<4> col;
    row[0] = input[0]; row[1] = input[5];
    for(int i = 0; i < 4; i++){
        col[i] = input[i+1];
    }
    int _row = (int)row.to_ulong();
    int _col = (int)col.to_ulong();
    bitset<4> retval(S_box[_row][_col]);
    return retval;
}

void DES::generate_round_keys()
{
    // Parity Drop
    bitset<56> updated_key_permuted; 
    for (int i = 0; i < 56; i++)
    {
        updated_key_permuted[55-i] = DES_key[INPUT_SIZE-1-(CP[i]-1)];
    }
    
    bitset<56> *temp;
    bitset<56> divider(0b00000000000000000000000000001111111111111111111111111111);
    // Split the input in two halves
    bitset<28> left(((updated_key_permuted >> 28) & divider).to_string().substr(28,28));
    bitset<28> right((updated_key_permuted & divider).to_string().substr(28, 28));

    for (int i = 0; i < 16; i++)
    {
        // rotate left according to round number
        switch (i + 1)
        {
        case 1:
        case 2:
        case 9:
        case 16: /* Rotate by 1 */
            
            left = left << 1 | left >> (27);
            right = right << 1 | right >> (27);
            
            break;

        default: /* Rotate by 2 */
            
            left = left << 2 | left >> (26);
            right = right << 2 | right >> (26);
            break;
        }
        
        // Concatenate the outputs left and right
        temp = new bitset<56>(left.to_string() + right.to_string());
        
        // Use Compression D-Box
        round_keys[i] = get_compression(temp, CD);
        delete temp;
    }
}

bitset<INPUT_SIZE> DES::swapper(bitset<INPUT_SIZE> set)
{
    int len = INPUT_SIZE;
    bitset<INPUT_SIZE> retval;
    retval = set << (len / 2) | set >> (len / 2);
    return retval;
}

bitset<INPUT_SIZE> DES::mixer(bitset<INPUT_SIZE> &input, bitset<ROUND_KEY_SIZE> &round_key)
{
    
    bitset<INPUT_SIZE / 2> function_output;
    bitset<INPUT_SIZE / 2> left(input.to_string().substr(0, INPUT_SIZE / 2));
    bitset<INPUT_SIZE / 2> right(input.to_string().substr(INPUT_SIZE / 2, INPUT_SIZE / 2));
    function_output = DES_function(right, round_key);
    left = left ^ function_output;
    bitset<INPUT_SIZE> mixer_output(left.to_string() + right.to_string());

    return mixer_output;
}

bitset<INPUT_SIZE / 2> DES::DES_function(bitset<32> &R, bitset<ROUND_KEY_SIZE> &round_key)
{
    
    // Expand the 'R' input by passing it through Expansion D box
    bitset<ROUND_KEY_SIZE> expanded_R;
    expanded_R = apply_expansion_permutation(R, ED);
    // XOR with round key
    bitset<ROUND_KEY_SIZE> intermediate1 = (expanded_R) ^ round_key;
    bitset<INPUT_SIZE / 2> intermediate2;
    // Split the intermediate output into 8 splits
    // modification
    string XORed = intermediate1.to_string();
    bitset<6> splits[8];
    for(int i = 0; i < 8; i++)
    {
        splits[i] = bitset<6>(XORed.substr(6*i, 6));
    }
    // Get corresponding substitutions
    // modification
    bitset<4> substitutions[8];
    bitset<2> row;
    bitset<4> col; 
    int _row, _col;
    for(int i = 0; i < 8; i++)
    {
        row[0] = splits[i][0]; row[1] = splits[i][5];
        for(int j = 1; j <= 4; j++)
        {
            col[j-1] = splits[i][j];
        }
        _row = (int) row.to_ulong();
        _col = (int) col.to_ulong(); 
        substitutions[i] = bitset<4>(S_boxes[i][_row][_col]);
    }
    
    string sub = "";
    for(int i = 0; i < 8; i++)
    {
        sub = sub + substitutions[i].to_string();
    }
    
    bitset<32> temp(sub);
    intermediate2 = temp;
    
    // Apply P-box
    apply_permutation(intermediate2, P);
    // Return the output
    return intermediate2;
}

int main()
{
    string key;
    string plain_text;
    string key_string = "";
    string plain_text_string = ""; 
    cin >> plain_text;
    cin >> key;
    bitset<8> t;
    for(int i = 0; i < 8; i++){
        t = bitset<8>(key.at(i));
        key_string = key_string + t.to_string();
        t = bitset<8>(plain_text.at(i));
        plain_text_string = plain_text_string + t.to_string();
    }
    bitset<KEY_SIZE> DES_Key(key_string);
    bitset<INPUT_SIZE> PlainText(plain_text_string);
    DES obj(PlainText, DES_Key, true);
    obj.setRoundKeysPresent(true);
    obj.DES_Decryption();
    return 0;
}