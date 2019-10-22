#include <bits/stdc++.h>
#define KEY_SIZE 128
#define INPUT_SIZE 128
#define BYTE_SIZE 8
#define WORD_SIZE 32
using namespace std;

bitset<BYTE_SIZE> SubByteTable[16][16] = {    
    {bitset<BYTE_SIZE>(0x63), bitset<BYTE_SIZE>(0x7C), bitset<BYTE_SIZE>(0x77), bitset<BYTE_SIZE>(0x7B), bitset<BYTE_SIZE>(0xF2), bitset<BYTE_SIZE>(0x6B), bitset<BYTE_SIZE>(0x6F), bitset<BYTE_SIZE>(0xC5), bitset<BYTE_SIZE>(0x30), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x67), bitset<BYTE_SIZE>(0x2B), bitset<BYTE_SIZE>(0xFE), bitset<BYTE_SIZE>(0xD7), bitset<BYTE_SIZE>(0xAB), bitset<BYTE_SIZE>(0x76)},
    {bitset<BYTE_SIZE>(0xCA), bitset<BYTE_SIZE>(0x82), bitset<BYTE_SIZE>(0xC9), bitset<BYTE_SIZE>(0x7D), bitset<BYTE_SIZE>(0xFA), bitset<BYTE_SIZE>(0x59), bitset<BYTE_SIZE>(0x47), bitset<BYTE_SIZE>(0xF0), bitset<BYTE_SIZE>(0xAD), bitset<BYTE_SIZE>(0xD4), bitset<BYTE_SIZE>(0xA2), bitset<BYTE_SIZE>(0xAF), bitset<BYTE_SIZE>(0x9C), bitset<BYTE_SIZE>(0xA4), bitset<BYTE_SIZE>(0x72), bitset<BYTE_SIZE>(0xC0)},
    {bitset<BYTE_SIZE>(0xB7), bitset<BYTE_SIZE>(0xFD), bitset<BYTE_SIZE>(0x93), bitset<BYTE_SIZE>(0x26), bitset<BYTE_SIZE>(0x36), bitset<BYTE_SIZE>(0x3F), bitset<BYTE_SIZE>(0xF7), bitset<BYTE_SIZE>(0xCC), bitset<BYTE_SIZE>(0x34), bitset<BYTE_SIZE>(0xA5), bitset<BYTE_SIZE>(0xE5), bitset<BYTE_SIZE>(0xF1), bitset<BYTE_SIZE>(0x71), bitset<BYTE_SIZE>(0xD8), bitset<BYTE_SIZE>(0x31), bitset<BYTE_SIZE>(0x15)},
    {bitset<BYTE_SIZE>(0x04), bitset<BYTE_SIZE>(0xC7), bitset<BYTE_SIZE>(0x23), bitset<BYTE_SIZE>(0xC3), bitset<BYTE_SIZE>(0x18), bitset<BYTE_SIZE>(0x96), bitset<BYTE_SIZE>(0x05), bitset<BYTE_SIZE>(0x9A), bitset<BYTE_SIZE>(0x07), bitset<BYTE_SIZE>(0x12), bitset<BYTE_SIZE>(0x80), bitset<BYTE_SIZE>(0xE2), bitset<BYTE_SIZE>(0xEB), bitset<BYTE_SIZE>(0x27), bitset<BYTE_SIZE>(0xB2), bitset<BYTE_SIZE>(0x75)},
    {bitset<BYTE_SIZE>(0x09), bitset<BYTE_SIZE>(0x83), bitset<BYTE_SIZE>(0x2C), bitset<BYTE_SIZE>(0x1A), bitset<BYTE_SIZE>(0x1B), bitset<BYTE_SIZE>(0x6E), bitset<BYTE_SIZE>(0x5A), bitset<BYTE_SIZE>(0xA0), bitset<BYTE_SIZE>(0x52), bitset<BYTE_SIZE>(0x3B), bitset<BYTE_SIZE>(0xD6), bitset<BYTE_SIZE>(0xB3), bitset<BYTE_SIZE>(0x29), bitset<BYTE_SIZE>(0xE3), bitset<BYTE_SIZE>(0x2F), bitset<BYTE_SIZE>(0x84)},
    {bitset<BYTE_SIZE>(0x53), bitset<BYTE_SIZE>(0xD1), bitset<BYTE_SIZE>(0x00), bitset<BYTE_SIZE>(0xED), bitset<BYTE_SIZE>(0x20), bitset<BYTE_SIZE>(0xFC), bitset<BYTE_SIZE>(0xB1), bitset<BYTE_SIZE>(0x5B), bitset<BYTE_SIZE>(0x6A), bitset<BYTE_SIZE>(0xCB), bitset<BYTE_SIZE>(0xBE), bitset<BYTE_SIZE>(0x39), bitset<BYTE_SIZE>(0x4A), bitset<BYTE_SIZE>(0x4C), bitset<BYTE_SIZE>(0x58), bitset<BYTE_SIZE>(0xCF)},
    {bitset<BYTE_SIZE>(0xD0), bitset<BYTE_SIZE>(0xEF), bitset<BYTE_SIZE>(0xAA), bitset<BYTE_SIZE>(0xFB), bitset<BYTE_SIZE>(0x43), bitset<BYTE_SIZE>(0x4D), bitset<BYTE_SIZE>(0x33), bitset<BYTE_SIZE>(0x85), bitset<BYTE_SIZE>(0x45), bitset<BYTE_SIZE>(0xF9), bitset<BYTE_SIZE>(0x02), bitset<BYTE_SIZE>(0x7F), bitset<BYTE_SIZE>(0x50), bitset<BYTE_SIZE>(0x3C), bitset<BYTE_SIZE>(0x9F), bitset<BYTE_SIZE>(0xA8)},
    {bitset<BYTE_SIZE>(0x51), bitset<BYTE_SIZE>(0xA3), bitset<BYTE_SIZE>(0x40), bitset<BYTE_SIZE>(0x8F), bitset<BYTE_SIZE>(0x92), bitset<BYTE_SIZE>(0x9D), bitset<BYTE_SIZE>(0x38), bitset<BYTE_SIZE>(0xF5), bitset<BYTE_SIZE>(0xBC), bitset<BYTE_SIZE>(0xB6), bitset<BYTE_SIZE>(0xDA), bitset<BYTE_SIZE>(0x21), bitset<BYTE_SIZE>(0x10), bitset<BYTE_SIZE>(0xFF), bitset<BYTE_SIZE>(0xF3), bitset<BYTE_SIZE>(0xD2)},
    {bitset<BYTE_SIZE>(0xCD), bitset<BYTE_SIZE>(0x0C), bitset<BYTE_SIZE>(0x13), bitset<BYTE_SIZE>(0xEC), bitset<BYTE_SIZE>(0x5F), bitset<BYTE_SIZE>(0x97), bitset<BYTE_SIZE>(0x44), bitset<BYTE_SIZE>(0x17), bitset<BYTE_SIZE>(0xC4), bitset<BYTE_SIZE>(0xA7), bitset<BYTE_SIZE>(0x7E), bitset<BYTE_SIZE>(0x3D), bitset<BYTE_SIZE>(0x64), bitset<BYTE_SIZE>(0x5D), bitset<BYTE_SIZE>(0x19), bitset<BYTE_SIZE>(0x73)},
    {bitset<BYTE_SIZE>(0x60), bitset<BYTE_SIZE>(0x81), bitset<BYTE_SIZE>(0x4F), bitset<BYTE_SIZE>(0xDC), bitset<BYTE_SIZE>(0x22), bitset<BYTE_SIZE>(0x2A), bitset<BYTE_SIZE>(0x90), bitset<BYTE_SIZE>(0x88), bitset<BYTE_SIZE>(0x46), bitset<BYTE_SIZE>(0xEE), bitset<BYTE_SIZE>(0xB8), bitset<BYTE_SIZE>(0x14), bitset<BYTE_SIZE>(0xDE), bitset<BYTE_SIZE>(0x5E), bitset<BYTE_SIZE>(0x0B), bitset<BYTE_SIZE>(0xDB)},
    {bitset<BYTE_SIZE>(0xE0), bitset<BYTE_SIZE>(0x32), bitset<BYTE_SIZE>(0x3A), bitset<BYTE_SIZE>(0x0A), bitset<BYTE_SIZE>(0x49), bitset<BYTE_SIZE>(0x06), bitset<BYTE_SIZE>(0x24), bitset<BYTE_SIZE>(0x5C), bitset<BYTE_SIZE>(0xC2), bitset<BYTE_SIZE>(0xD3), bitset<BYTE_SIZE>(0xAC), bitset<BYTE_SIZE>(0x62), bitset<BYTE_SIZE>(0x91), bitset<BYTE_SIZE>(0x95), bitset<BYTE_SIZE>(0xE4), bitset<BYTE_SIZE>(0x79)},
    {bitset<BYTE_SIZE>(0xE7), bitset<BYTE_SIZE>(0xC8), bitset<BYTE_SIZE>(0x37), bitset<BYTE_SIZE>(0x6D), bitset<BYTE_SIZE>(0x8D), bitset<BYTE_SIZE>(0xD5), bitset<BYTE_SIZE>(0x4E), bitset<BYTE_SIZE>(0xA9), bitset<BYTE_SIZE>(0x6C), bitset<BYTE_SIZE>(0x56), bitset<BYTE_SIZE>(0xF4), bitset<BYTE_SIZE>(0xEA), bitset<BYTE_SIZE>(0x65), bitset<BYTE_SIZE>(0x7A), bitset<BYTE_SIZE>(0xAE), bitset<BYTE_SIZE>(0x08)},
    {bitset<BYTE_SIZE>(0xBA), bitset<BYTE_SIZE>(0x78), bitset<BYTE_SIZE>(0x25), bitset<BYTE_SIZE>(0x2E), bitset<BYTE_SIZE>(0x1C), bitset<BYTE_SIZE>(0xA6), bitset<BYTE_SIZE>(0xB4), bitset<BYTE_SIZE>(0xC6), bitset<BYTE_SIZE>(0xE8), bitset<BYTE_SIZE>(0xDD), bitset<BYTE_SIZE>(0x74), bitset<BYTE_SIZE>(0x1F), bitset<BYTE_SIZE>(0x4B), bitset<BYTE_SIZE>(0xBD), bitset<BYTE_SIZE>(0x8B), bitset<BYTE_SIZE>(0x8A)},
    {bitset<BYTE_SIZE>(0x70), bitset<BYTE_SIZE>(0x3E), bitset<BYTE_SIZE>(0xB5), bitset<BYTE_SIZE>(0x66), bitset<BYTE_SIZE>(0x48), bitset<BYTE_SIZE>(0x03), bitset<BYTE_SIZE>(0xF6), bitset<BYTE_SIZE>(0x0E), bitset<BYTE_SIZE>(0x61), bitset<BYTE_SIZE>(0x35), bitset<BYTE_SIZE>(0x57), bitset<BYTE_SIZE>(0xB9), bitset<BYTE_SIZE>(0x86), bitset<BYTE_SIZE>(0xC1), bitset<BYTE_SIZE>(0x1D), bitset<BYTE_SIZE>(0x9E)},
    {bitset<BYTE_SIZE>(0xE1), bitset<BYTE_SIZE>(0xF8), bitset<BYTE_SIZE>(0x98), bitset<BYTE_SIZE>(0x11), bitset<BYTE_SIZE>(0x69), bitset<BYTE_SIZE>(0xD9), bitset<BYTE_SIZE>(0x8E), bitset<BYTE_SIZE>(0x94), bitset<BYTE_SIZE>(0x9B), bitset<BYTE_SIZE>(0x1E), bitset<BYTE_SIZE>(0x87), bitset<BYTE_SIZE>(0xE9), bitset<BYTE_SIZE>(0xCE), bitset<BYTE_SIZE>(0x55), bitset<BYTE_SIZE>(0x28), bitset<BYTE_SIZE>(0xDF)},
    {bitset<BYTE_SIZE>(0x8C), bitset<BYTE_SIZE>(0xA1), bitset<BYTE_SIZE>(0x89), bitset<BYTE_SIZE>(0x0D), bitset<BYTE_SIZE>(0xBF), bitset<BYTE_SIZE>(0xE6), bitset<BYTE_SIZE>(0x42), bitset<BYTE_SIZE>(0x68), bitset<BYTE_SIZE>(0x41), bitset<BYTE_SIZE>(0x99), bitset<BYTE_SIZE>(0x2D), bitset<BYTE_SIZE>(0x0F), bitset<BYTE_SIZE>(0xB0), bitset<BYTE_SIZE>(0x54), bitset<BYTE_SIZE>(0xBB), bitset<BYTE_SIZE>(0x16)}
};

bitset<BYTE_SIZE> InvSubByteTable[16][16] = {
    {bitset<BYTE_SIZE>(0x52), bitset<BYTE_SIZE>(0x09), bitset<BYTE_SIZE>(0x6a), bitset<BYTE_SIZE>(0xd5), bitset<BYTE_SIZE>(0x30), bitset<BYTE_SIZE>(0x36), bitset<BYTE_SIZE>(0xa5), bitset<BYTE_SIZE>(0x38), bitset<BYTE_SIZE>(0xbf), bitset<BYTE_SIZE>(0x40), bitset<BYTE_SIZE>(0xa3), bitset<BYTE_SIZE>(0x9e), bitset<BYTE_SIZE>(0x81), bitset<BYTE_SIZE>(0xf3), bitset<BYTE_SIZE>(0xd7), bitset<BYTE_SIZE>(0xfb)},
    {bitset<BYTE_SIZE>(0x7c), bitset<BYTE_SIZE>(0xe3), bitset<BYTE_SIZE>(0x39), bitset<BYTE_SIZE>(0x82), bitset<BYTE_SIZE>(0x9b), bitset<BYTE_SIZE>(0x2f), bitset<BYTE_SIZE>(0xff), bitset<BYTE_SIZE>(0x87), bitset<BYTE_SIZE>(0x34), bitset<BYTE_SIZE>(0x8e), bitset<BYTE_SIZE>(0x43), bitset<BYTE_SIZE>(0x44), bitset<BYTE_SIZE>(0xc4), bitset<BYTE_SIZE>(0xde), bitset<BYTE_SIZE>(0xe9), bitset<BYTE_SIZE>(0xcb)},
    {bitset<BYTE_SIZE>(0x54), bitset<BYTE_SIZE>(0x7b), bitset<BYTE_SIZE>(0x94), bitset<BYTE_SIZE>(0x32), bitset<BYTE_SIZE>(0xa6), bitset<BYTE_SIZE>(0xc2), bitset<BYTE_SIZE>(0x23), bitset<BYTE_SIZE>(0x3d), bitset<BYTE_SIZE>(0xee), bitset<BYTE_SIZE>(0x4c), bitset<BYTE_SIZE>(0x95), bitset<BYTE_SIZE>(0x0b), bitset<BYTE_SIZE>(0x42), bitset<BYTE_SIZE>(0xfa), bitset<BYTE_SIZE>(0xc3), bitset<BYTE_SIZE>(0x4e)},
    {bitset<BYTE_SIZE>(0x08), bitset<BYTE_SIZE>(0x2e), bitset<BYTE_SIZE>(0xa1), bitset<BYTE_SIZE>(0x66), bitset<BYTE_SIZE>(0x28), bitset<BYTE_SIZE>(0xd9), bitset<BYTE_SIZE>(0x24), bitset<BYTE_SIZE>(0xb2), bitset<BYTE_SIZE>(0x76), bitset<BYTE_SIZE>(0x5b), bitset<BYTE_SIZE>(0xa2), bitset<BYTE_SIZE>(0x49), bitset<BYTE_SIZE>(0x6d), bitset<BYTE_SIZE>(0x8b), bitset<BYTE_SIZE>(0xd1), bitset<BYTE_SIZE>(0x25)},
    {bitset<BYTE_SIZE>(0x72), bitset<BYTE_SIZE>(0xf8), bitset<BYTE_SIZE>(0xf6), bitset<BYTE_SIZE>(0x64), bitset<BYTE_SIZE>(0x86), bitset<BYTE_SIZE>(0x68), bitset<BYTE_SIZE>(0x98), bitset<BYTE_SIZE>(0x16), bitset<BYTE_SIZE>(0xd4), bitset<BYTE_SIZE>(0xa4), bitset<BYTE_SIZE>(0x5c), bitset<BYTE_SIZE>(0xcc), bitset<BYTE_SIZE>(0x5d), bitset<BYTE_SIZE>(0x65), bitset<BYTE_SIZE>(0xb6), bitset<BYTE_SIZE>(0x92)},
    {bitset<BYTE_SIZE>(0x6c), bitset<BYTE_SIZE>(0x70), bitset<BYTE_SIZE>(0x48), bitset<BYTE_SIZE>(0x50), bitset<BYTE_SIZE>(0xfd), bitset<BYTE_SIZE>(0xed), bitset<BYTE_SIZE>(0xb9), bitset<BYTE_SIZE>(0xda), bitset<BYTE_SIZE>(0x5e), bitset<BYTE_SIZE>(0x15), bitset<BYTE_SIZE>(0x46), bitset<BYTE_SIZE>(0x57), bitset<BYTE_SIZE>(0xa7), bitset<BYTE_SIZE>(0x8d), bitset<BYTE_SIZE>(0x9d), bitset<BYTE_SIZE>(0x84)},
    {bitset<BYTE_SIZE>(0x90), bitset<BYTE_SIZE>(0xd8), bitset<BYTE_SIZE>(0xab), bitset<BYTE_SIZE>(0x00), bitset<BYTE_SIZE>(0x8c), bitset<BYTE_SIZE>(0xbc), bitset<BYTE_SIZE>(0xd3), bitset<BYTE_SIZE>(0x0a), bitset<BYTE_SIZE>(0xf7), bitset<BYTE_SIZE>(0xe4), bitset<BYTE_SIZE>(0x58), bitset<BYTE_SIZE>(0x05), bitset<BYTE_SIZE>(0xb8), bitset<BYTE_SIZE>(0xb3), bitset<BYTE_SIZE>(0x45), bitset<BYTE_SIZE>(0x06)},
    {bitset<BYTE_SIZE>(0xd0), bitset<BYTE_SIZE>(0x2c), bitset<BYTE_SIZE>(0x1e), bitset<BYTE_SIZE>(0x8f), bitset<BYTE_SIZE>(0xca), bitset<BYTE_SIZE>(0x3f), bitset<BYTE_SIZE>(0x0f), bitset<BYTE_SIZE>(0x02), bitset<BYTE_SIZE>(0xc1), bitset<BYTE_SIZE>(0xaf), bitset<BYTE_SIZE>(0xbd), bitset<BYTE_SIZE>(0x03), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x13), bitset<BYTE_SIZE>(0x8a), bitset<BYTE_SIZE>(0x6b)},
    {bitset<BYTE_SIZE>(0x3a), bitset<BYTE_SIZE>(0x91), bitset<BYTE_SIZE>(0x11), bitset<BYTE_SIZE>(0x41), bitset<BYTE_SIZE>(0x4f), bitset<BYTE_SIZE>(0x67), bitset<BYTE_SIZE>(0xdc), bitset<BYTE_SIZE>(0xea), bitset<BYTE_SIZE>(0x97), bitset<BYTE_SIZE>(0xf2), bitset<BYTE_SIZE>(0xcf), bitset<BYTE_SIZE>(0xce), bitset<BYTE_SIZE>(0xf0), bitset<BYTE_SIZE>(0xb4), bitset<BYTE_SIZE>(0xe6), bitset<BYTE_SIZE>(0x73)},
    {bitset<BYTE_SIZE>(0x96), bitset<BYTE_SIZE>(0xac), bitset<BYTE_SIZE>(0x74), bitset<BYTE_SIZE>(0x22), bitset<BYTE_SIZE>(0xe7), bitset<BYTE_SIZE>(0xad), bitset<BYTE_SIZE>(0x35), bitset<BYTE_SIZE>(0x85), bitset<BYTE_SIZE>(0xe2), bitset<BYTE_SIZE>(0xf9), bitset<BYTE_SIZE>(0x37), bitset<BYTE_SIZE>(0xe8), bitset<BYTE_SIZE>(0x1c), bitset<BYTE_SIZE>(0x75), bitset<BYTE_SIZE>(0xdf), bitset<BYTE_SIZE>(0x6e)},
    {bitset<BYTE_SIZE>(0x47), bitset<BYTE_SIZE>(0xf1), bitset<BYTE_SIZE>(0x1a), bitset<BYTE_SIZE>(0x71), bitset<BYTE_SIZE>(0x1d), bitset<BYTE_SIZE>(0x29), bitset<BYTE_SIZE>(0xc5), bitset<BYTE_SIZE>(0x89), bitset<BYTE_SIZE>(0x6f), bitset<BYTE_SIZE>(0xb7), bitset<BYTE_SIZE>(0x62), bitset<BYTE_SIZE>(0x0e), bitset<BYTE_SIZE>(0xaa), bitset<BYTE_SIZE>(0x18), bitset<BYTE_SIZE>(0xbe), bitset<BYTE_SIZE>(0x1b)},
    {bitset<BYTE_SIZE>(0xfc), bitset<BYTE_SIZE>(0x56), bitset<BYTE_SIZE>(0x3e), bitset<BYTE_SIZE>(0x4b), bitset<BYTE_SIZE>(0xc6), bitset<BYTE_SIZE>(0xd2), bitset<BYTE_SIZE>(0x79), bitset<BYTE_SIZE>(0x20), bitset<BYTE_SIZE>(0x9a), bitset<BYTE_SIZE>(0xdb), bitset<BYTE_SIZE>(0xc0), bitset<BYTE_SIZE>(0xfe), bitset<BYTE_SIZE>(0x78), bitset<BYTE_SIZE>(0xcd), bitset<BYTE_SIZE>(0x5a), bitset<BYTE_SIZE>(0xf4)},
    {bitset<BYTE_SIZE>(0x1f), bitset<BYTE_SIZE>(0xdd), bitset<BYTE_SIZE>(0xa8), bitset<BYTE_SIZE>(0x33), bitset<BYTE_SIZE>(0x88), bitset<BYTE_SIZE>(0x07), bitset<BYTE_SIZE>(0xc7), bitset<BYTE_SIZE>(0x31), bitset<BYTE_SIZE>(0xb1), bitset<BYTE_SIZE>(0x12), bitset<BYTE_SIZE>(0x10), bitset<BYTE_SIZE>(0x59), bitset<BYTE_SIZE>(0x27), bitset<BYTE_SIZE>(0x80), bitset<BYTE_SIZE>(0xec), bitset<BYTE_SIZE>(0x5f)},
    {bitset<BYTE_SIZE>(0x60), bitset<BYTE_SIZE>(0x51), bitset<BYTE_SIZE>(0x7f), bitset<BYTE_SIZE>(0xa9), bitset<BYTE_SIZE>(0x19), bitset<BYTE_SIZE>(0xb5), bitset<BYTE_SIZE>(0x4a), bitset<BYTE_SIZE>(0x0d), bitset<BYTE_SIZE>(0x2d), bitset<BYTE_SIZE>(0xe5), bitset<BYTE_SIZE>(0x7a), bitset<BYTE_SIZE>(0x9f), bitset<BYTE_SIZE>(0x93), bitset<BYTE_SIZE>(0xc9), bitset<BYTE_SIZE>(0x9c), bitset<BYTE_SIZE>(0xef)},
    {bitset<BYTE_SIZE>(0xa0), bitset<BYTE_SIZE>(0xe0), bitset<BYTE_SIZE>(0x3b), bitset<BYTE_SIZE>(0x4d), bitset<BYTE_SIZE>(0xae), bitset<BYTE_SIZE>(0x2a), bitset<BYTE_SIZE>(0xf5), bitset<BYTE_SIZE>(0xb0), bitset<BYTE_SIZE>(0xc8), bitset<BYTE_SIZE>(0xeb), bitset<BYTE_SIZE>(0xbb), bitset<BYTE_SIZE>(0x3c), bitset<BYTE_SIZE>(0x83), bitset<BYTE_SIZE>(0x53), bitset<BYTE_SIZE>(0x99), bitset<BYTE_SIZE>(0x61)},
    {bitset<BYTE_SIZE>(0x17), bitset<BYTE_SIZE>(0x2b), bitset<BYTE_SIZE>(0x04), bitset<BYTE_SIZE>(0x7e), bitset<BYTE_SIZE>(0xba), bitset<BYTE_SIZE>(0x77), bitset<BYTE_SIZE>(0xd6), bitset<BYTE_SIZE>(0x26), bitset<BYTE_SIZE>(0xe1), bitset<BYTE_SIZE>(0x69), bitset<BYTE_SIZE>(0x14), bitset<BYTE_SIZE>(0x63), bitset<BYTE_SIZE>(0x55), bitset<BYTE_SIZE>(0x21), bitset<BYTE_SIZE>(0x0c), bitset<BYTE_SIZE>(0x7d)}
};

bitset<4> HexToBinary(char c){
    bitset<4> retval;
    switch(c)
    {
        case '0': retval = bitset<4>(0x0); break;
        case '1': retval = bitset<4>(0x1); break;
        case '2': retval = bitset<4>(0x2); break;
        case '3': retval = bitset<4>(0x3); break;
        case '4': retval = bitset<4>(0x4); break;
        case '5': retval = bitset<4>(0x5); break;
        case '6': retval = bitset<4>(0x6); break;
        case '7': retval = bitset<4>(0x7); break;
        case '8': retval = bitset<4>(0x8); break;
        case '9': retval = bitset<4>(0x9); break;
        case 'a': retval = bitset<4>(0xA); break;
        case 'b': retval = bitset<4>(0xB); break;
        case 'c': retval = bitset<4>(0xC); break;
        case 'd': retval = bitset<4>(0xD); break;
        case 'e': retval = bitset<4>(0xE); break;
        case 'f': retval = bitset<4>(0xF); break;
    }
    return retval;
}

char BinaryToHex(bitset<4> b)
{
    char retval;
    int int_val = (int) b.to_ulong();
    switch(int_val)
    {
        case 0: retval = '0'; break;
        case 1: retval = '1'; break;
        case 2: retval = '2'; break;
        case 3: retval = '3'; break;
        case 4: retval = '4'; break;
        case 5: retval = '5'; break;
        case 6: retval = '6'; break;
        case 7: retval = '7'; break;
        case 8: retval = '8'; break;
        case 9: retval = '9'; break;
        case 10: retval = 'a'; break;
        case 11: retval = 'b'; break;
        case 12: retval = 'c'; break;
        case 13: retval = 'd'; break;
        case 14: retval = 'e'; break;
        case 15: retval = 'f'; break;
    }
    return retval;
}

int modulo(int a, int n) // Return a mod n
{
    if(a >= 0){
        return a%n;
    }else{
        int q = (-a)/n, r = (-a)%n;
        if(r == 0){
            return 0;
        }else{
            return a + (q+1)*n;
        }
    }
}

int get_degree(bitset<BYTE_SIZE>& polynomial)
{
    for(int i = BYTE_SIZE-1; i >=0; i--){
        if(polynomial.test(i))
        {
            return i;
        }
    }
    return 0;
}

bitset<BYTE_SIZE> polynomial_multiplication(bitset<BYTE_SIZE>& poly1, bitset<BYTE_SIZE>& poly2)
{
    bitset<BYTE_SIZE> modulo_polynomial(0b00011011);
    bitset<BYTE_SIZE> Poly2 = poly2;
    bitset<BYTE_SIZE> result;
    bool xor_flag = false;
    for(int i = 0; i < 8; i++) // Try get_degree()
    {
        if(Poly2.test(7)){
            xor_flag = true;
        }
        if(poly1.test(i)){
            result = result ^ Poly2;
        }
        Poly2 = Poly2 << 1;
        if(xor_flag){
            Poly2 = Poly2 ^ modulo_polynomial;
            xor_flag = false;
        } 
    }
    return result;
}

bitset<8> multiplicative_inverse(bitset<8> input_polynomial)
{
    //pass
}

bitset<WORD_SIZE> RotWord(bitset<WORD_SIZE> input_word)
{
    bitset<WORD_SIZE> retval(input_word.to_string().substr(8, 24) + input_word.to_string().substr(0,8));
    return retval;
}

bitset<WORD_SIZE> SubWord(bitset<WORD_SIZE> input)
{
    string result = "";
    for(int i = 0; i < WORD_SIZE-1; i+=BYTE_SIZE)
    {
        bitset<4> row(input.to_string().substr(i, 4));
        bitset<4> col(input.to_string().substr(i+4, 4));
        int r = (int) BinaryToHex(row) - '0';
        int c = (int) BinaryToHex(col) - '0';
        if(r > 9) {
            r = (int) BinaryToHex(row) - 'a' + 10;
        }
        if(c > 9) {
            c = (int) BinaryToHex(col) - 'a' + 10;
        }
        result = result + (SubByteTable[r][c]).to_string();
    }
    return bitset<WORD_SIZE>(result); 
}

void printBitsetInHex(bitset<WORD_SIZE>& word)
{
    string word_string = word.to_string();
    for(int i = 0; i < WORD_SIZE; i+=4){
        cout << BinaryToHex(bitset<4>(word_string.substr(i, 4)));
    }
    cout << " ";
}

class AES
{
    private:
        bitset<INPUT_SIZE> Input;
        bitset<INPUT_SIZE> Output;
        vector<vector<bitset<BYTE_SIZE>>> state;
        vector<vector<bitset<BYTE_SIZE>>> D_state;
        bitset<KEY_SIZE> AES_key;
        bitset<BYTE_SIZE> ConstMatrix[4][4] = {
            {bitset<BYTE_SIZE>(0x02), bitset<BYTE_SIZE>(0x03), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x01)},
            {bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x02), bitset<BYTE_SIZE>(0x03), bitset<BYTE_SIZE>(0x01)},
            {bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x02), bitset<BYTE_SIZE>(0x03)},
            {bitset<BYTE_SIZE>(0x03), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x01), bitset<BYTE_SIZE>(0x02)}
        };
        bitset<BYTE_SIZE> InvConstMatrix[4][4] = {
            {bitset<BYTE_SIZE>(0x0E), bitset<BYTE_SIZE>(0x0B), bitset<BYTE_SIZE>(0x0D), bitset<BYTE_SIZE>(0x09)},
            {bitset<BYTE_SIZE>(0x09), bitset<BYTE_SIZE>(0x0E), bitset<BYTE_SIZE>(0x0B), bitset<BYTE_SIZE>(0x0D)},
            {bitset<BYTE_SIZE>(0x0D), bitset<BYTE_SIZE>(0x09), bitset<BYTE_SIZE>(0x0E), bitset<BYTE_SIZE>(0x0B)},
            {bitset<BYTE_SIZE>(0x0B), bitset<BYTE_SIZE>(0x0D), bitset<BYTE_SIZE>(0x09), bitset<BYTE_SIZE>(0x0E)}
        };
        
        bitset<WORD_SIZE> KeyMatrix[11][4];
        bitset<WORD_SIZE> RCons[10] = {
            bitset<WORD_SIZE>(0x01000000),
            bitset<WORD_SIZE>(0x02000000),
            bitset<WORD_SIZE>(0x04000000),
            bitset<WORD_SIZE>(0x08000000),
            bitset<WORD_SIZE>(0x10000000),
            bitset<WORD_SIZE>(0x20000000),
            bitset<WORD_SIZE>(0x40000000),
            bitset<WORD_SIZE>(0x80000000),
            bitset<WORD_SIZE>(0x1B000000),
            bitset<WORD_SIZE>(0x36000000)
        };
        void KeyExpansion();
        void AddRoundKey(int round_number, bool e_or_d);
        // Encryption methods
        void SubBytes();
        void ShiftRows();
        void MixColumns();
        void AES_Encryption_Round(int round_number);
        // Decryption methods
        void InvSubBytes();
        void InvShiftRows();
        void InvMixColumns();
        void AES_Decryption_Round(int round_number);
    public:
        AES(string& AES_Key);
        void printState(bool e_or_d);
        string AES_Encryption(string& PlainText, bool is_empty);
        string AES_Decryption(string& CipherText, bool is_empty);
        
};

AES::AES(string& AES_key)
{
    this->AES_key = bitset<KEY_SIZE>(AES_key);
    this->KeyExpansion();
}

void AES::KeyExpansion()
{
    string AES_Key_string = AES_key.to_string();
    for(int j = 0; j < KEY_SIZE; j += WORD_SIZE)
    {
        KeyMatrix[0][j / WORD_SIZE] = bitset<WORD_SIZE>(AES_Key_string.substr(j, WORD_SIZE));
    }
    for(int i = 1; i < 11; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(j != 0) 
            {
                KeyMatrix[i][j] = KeyMatrix[i][j-1] ^ KeyMatrix[i-1][j];
            }
            else
            {
                bitset<WORD_SIZE> t = SubWord(RotWord(KeyMatrix[i-1][3])) ^ RCons[i-1];
                KeyMatrix[i][j] = t ^ KeyMatrix[i-1][0];
            }   
        }
    }
}

void AES::printState(bool e_or_d)
{
    string str;
    if(e_or_d == true){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                str = state[j][i].to_string();
                cout << BinaryToHex(bitset<4>(str.substr(0,4))) << BinaryToHex(bitset<4>(str.substr(4,4)));
            }
        }
        cout << endl;
    }else{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                str = D_state[j][i].to_string();
                cout << BinaryToHex(bitset<4>(str.substr(0,4))) << BinaryToHex(bitset<4>(str.substr(4,4)));
            }
        }
        cout << endl;
    }
    
}

string AES::AES_Encryption(string& PlainText, bool is_empty)
{
    if(is_empty) // First block of 128 bits
    {
        for(int i = 0; i < 4; i++)
        {
            vector<bitset<BYTE_SIZE>> word;
            for(int j = BYTE_SIZE*i; j < INPUT_SIZE-1; j+=32)
            {
                word.push_back(bitset<BYTE_SIZE>(PlainText.substr(j, BYTE_SIZE)));
            }
            state.push_back(word);
        }
    }
    else // Subsequent blocks of 128 bits
    {
        int k = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                state[j][i] = bitset<BYTE_SIZE>(PlainText.substr(k, BYTE_SIZE));
                k += 8;
            }
        }
    }
    
    for(int round = 0; round <= 10; round++)
    {
        AES_Encryption_Round(round);
    }
    string result = "";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            string temp = state[j][i].to_string();
            result = result + BinaryToHex(bitset<4>(temp.substr(0,4))) + BinaryToHex(bitset<4>(temp.substr(4,4)));
        }
    }
    return result;
}   

void AES::SubBytes()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            bitset<4> row(state[j][i].to_string().substr(0, 4));
            bitset<4> col(state[j][i].to_string().substr(4, 4));
            int r = (int) BinaryToHex(row) - '0';
            int c = (int) BinaryToHex(col) - '0';
            if(r > 9) {
                r = (int) BinaryToHex(row) - 'a' + 10;
            }
            if(c > 9) {
                c = (int) BinaryToHex(col) - 'a' + 10;
            }
            state[j][i] = SubByteTable[r][c];
        }
    }
}

void AES::ShiftRows()
{
    vector<vector<bitset<BYTE_SIZE>>> temp;
    for(int i = 0; i < 4; i++){
        vector<bitset<BYTE_SIZE>> t;
        for(int j = 0; j < 4; j++){
            t.push_back(state[i][modulo(i+j, 4)]);
        }
        temp.push_back(t);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            state[i][j] = temp[i][j];
        }
    }
}

void AES::MixColumns()
{
    for(int i = 0; i < 4; i++)
    {
        vector<bitset<BYTE_SIZE>> column;
        vector<bitset<BYTE_SIZE>> multiplied_column;
        for(int j = 0; j < 4; j++)
        {
            column.push_back(state[j][i]); // (j, i) for column
        }
        for(int k = 0; k < 4; k++)
        {
            bitset<BYTE_SIZE> xor_result;
            for(int l = 0; l < 4; l++)
            {
                xor_result = xor_result ^ polynomial_multiplication(ConstMatrix[k][l], column[l]);
            }
            multiplied_column.push_back(xor_result);
        }
        for(int j = 0; j < 4; j++)
        {
            state[j][i] = multiplied_column[j];
        }
    }
}

void AES::AddRoundKey(int round_number, bool e_or_d)
{
    if(e_or_d == true) // Encryption mode
    {
        for(int i = 0; i < 4; i++)
        {
            string current_key = (KeyMatrix[round_number-1][i]).to_string();
            //cout << "i = " << i << " current key: "; printBitsetInHex(KeyMatrix[round_number-1][i]); cout << endl;
            for(int j = 0; j < 4; j++)
            {
                
                state[j][i] = state[j][i] ^ bitset<BYTE_SIZE>(current_key.substr(BYTE_SIZE*j, BYTE_SIZE));
            }
        }
    }
    else // Decryption mode
    {
        for(int i = 0; i < 4; i++)
        {
            string current_key = (KeyMatrix[round_number-1][i]).to_string();
            //cout << "i = " << i << " current key: "; printBitsetInHex(KeyMatrix[round_number-1][i]); cout << endl;
            for(int j = 0; j < 4; j++)
            {
                
                D_state[j][i] = D_state[j][i] ^ bitset<BYTE_SIZE>(current_key.substr(BYTE_SIZE*j, BYTE_SIZE));
            }
        }
    }
}

void AES::AES_Encryption_Round(int round_number)
{
    if(round_number == 0){
        // Pre-Round transformation
        AddRoundKey(1, true);
    }else if(round_number < 10){
        SubBytes();
        ShiftRows();
        MixColumns();
        AddRoundKey(round_number+1, true);
    }else if(round_number == 10){
        SubBytes();
        ShiftRows();
        AddRoundKey(11, true);
    }
}

string AES::AES_Decryption(string& CipherText, bool is_empty)
{
    if(is_empty){ // First Block of 128 bits
        for(int i = 0; i < 4; i++)
        {
            vector<bitset<BYTE_SIZE>> word;
            for(int j = BYTE_SIZE*i; j < INPUT_SIZE-1; j+=32)
            {
                word.push_back(bitset<BYTE_SIZE>(CipherText.substr(j, BYTE_SIZE)));
            }
            D_state.push_back(word);
        }
    }else{ // Subsequent blocks of 128 bits
        int k = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                D_state[j][i] = bitset<BYTE_SIZE>(CipherText.substr(k, BYTE_SIZE));
                k += 8;
            }
        }
    }
    
    for(int round = 10; round >= 0; round--)
    {
        AES_Decryption_Round(round);
    }
    string result = "";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            string temp = D_state[j][i].to_string();
            result = result + BinaryToHex(bitset<4>(temp.substr(0,4))) + BinaryToHex(bitset<4>(temp.substr(4,4)));
        }
    }
    return result;
}

void AES::AES_Decryption_Round(int round_number)
{
    if(round_number == 10){
        // Pre-Round transformation
        AddRoundKey(11, false);
    }else if(round_number < 10 && round_number != 0){
        InvShiftRows();
        InvSubBytes();
        AddRoundKey(round_number+1, false);
        InvMixColumns();
    }else if(round_number == 0){
        InvShiftRows();
        InvSubBytes();
        AddRoundKey(1, false);
    }
}

void AES::InvMixColumns()
{
    for(int i = 0; i < 4; i++)
    {
        vector<bitset<BYTE_SIZE>> column;
        vector<bitset<BYTE_SIZE>> multiplied_column;
        for(int j = 0; j < 4; j++)
        {
            column.push_back(D_state[j][i]); // (j, i) for column
        }
        for(int k = 0; k < 4; k++)
        {
            bitset<BYTE_SIZE> xor_result;
            for(int l = 0; l < 4; l++)
            {
                xor_result = xor_result ^ polynomial_multiplication(InvConstMatrix[k][l], column[l]);
            }
            multiplied_column.push_back(xor_result);
        }
        for(int j = 0; j < 4; j++)
        {
            D_state[j][i] = multiplied_column[j];
        }
    }
}

void AES::InvShiftRows()
{
    vector<vector<bitset<BYTE_SIZE>>> temp;
    for(int i = 0; i < 4; i++){
        vector<bitset<BYTE_SIZE>> t;
        for(int j = 0; j < 4; j++){
            t.push_back(D_state[i][modulo(j-i, 4)]);
        }
        temp.push_back(t);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            D_state[i][j] = temp[i][j];
        }
    }
}

void AES::InvSubBytes()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            bitset<4> row(D_state[j][i].to_string().substr(0, 4));
            bitset<4> col(D_state[j][i].to_string().substr(4, 4));
            int r = (int) BinaryToHex(row) - '0';
            int c = (int) BinaryToHex(col) - '0';
            if(r > 9) {
                r = (int) BinaryToHex(row) - 'a' + 10;
            }
            if(c > 9) {
                c = (int) BinaryToHex(col) - 'a' + 10;
            }
            D_state[j][i] = InvSubByteTable[r][c];
        }
    }
}

int main()
{
    //cout << "Hello AES!" << endl;
    string plain_text_hex; string plain_text_bin = "";
    string AES_key_hex; string AES_key_bin = "";
    cin >> plain_text_hex;
    cin >> AES_key_hex;
    int plain_text_length = plain_text_hex.length(); // Actual length.
    int pad_characters = 32 - (plain_text_length % 32); // this many 0s we have to append to the last block of plain text
    if(pad_characters != 32){
        for(int i = 0; i < pad_characters; i++){
            plain_text_hex = plain_text_hex + '0';
        }  
    }
    //cout << "plain text hex: " << plain_text_hex << endl;
    for(int i = 0; i < plain_text_hex.length(); i++){
        plain_text_bin = plain_text_bin + HexToBinary(plain_text_hex.at(i)).to_string();
    }
    for(int i = 0; i < AES_key_hex.length(); i++){
        AES_key_bin = AES_key_bin + HexToBinary(AES_key_hex.at(i)).to_string();
    }
    
    bool is_empty = true;
    AES* obj = new AES(AES_key_bin);

    // Encryption ECB Mode
    string cipher_text_hex = "";
    for(int i = 0; i < plain_text_bin.length(); i+=INPUT_SIZE){
        string piece = plain_text_bin.substr(i, INPUT_SIZE);
        if(i == 0){
            is_empty = true;
        }else{
            is_empty = false;
        }
        string enc = obj->AES_Encryption(piece, is_empty);
        cout << enc;
        cipher_text_hex = cipher_text_hex + enc;
    }
    cout << endl;

    // Decryption ECB mode
    is_empty = true;
    string cipher_text_bin = "";
    for(int i = 0; i < cipher_text_hex.length(); i++){
        cipher_text_bin = cipher_text_bin + HexToBinary(cipher_text_hex.at(i)).to_string();
    }
    string decryption = "";
    for(int i = 0; i < cipher_text_bin.length(); i+=INPUT_SIZE){
        string piece = cipher_text_bin.substr(i, INPUT_SIZE);
        if(i == 0){
            is_empty = true;
        }else{
            is_empty = false;
        }
        string dec = obj->AES_Decryption(piece, is_empty);
        decryption = decryption + dec;
        //cout << dec;
    }
    cout << decryption.substr(0, plain_text_length) << endl; // Remove the excess padded zeros

    return 0;
}
// Sample Input: 00112233445566778899aabbccddeeff Key: 000102030405060708090a0b0c0d0e0f
// SampleOutput: 69c4e0d86a7b0430d8cdb78070b4c55a DEc: 00112233445566778899aabbccddeeff
