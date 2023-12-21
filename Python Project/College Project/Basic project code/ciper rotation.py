def caesar_cipher(text, shift):
    result = ""

    for i in range(len(text)):
        char = text[i]
        char_1 = char.upper()
        order = (ord(char_1) + shift)
        if order == (ord(char_1) - shift):
            result += chr(order)    
        if order <= 90:
            result += chr(order)    
        else:
            if order > 90:
                order_1 = 64
                result += chr(order_1 + shift)
            else:
                order < 65
                order_2 = 90
                result += chr(order_1 + shift)
    return result

def main():
    text = input("Your message? ")
    shift = int(input("Encoding key? "))

    encrypted_text = caesar_cipher(text, shift)
    print(encrypted_text)

if __name__ == "__main__":
    main()

