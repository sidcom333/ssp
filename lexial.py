import re

class Token:
    def __init__(self, type, value):
        self.type = type
        self.value = value

    def __str__(self):
        return f'Token({self.type}, {self.value})'

class Lexer:
    def __init__(self, text):
        self.text = text
        self.pos = 0

    def error(self):
        raise Exception('Invalid character')

    def get_next_token(self):
        if self.pos >= len(self.text):
            return Token('EOF', None)

        current_char = self.text[self.pos]

        if re.match(r'\d', current_char):
            token = self.tokenize_number()
        elif current_char == '+':
            token = Token('PLUS', current_char)
            self.pos += 1
        elif current_char == '-':
            token = Token('MINUS', current_char)
            self.pos += 1
        elif current_char == '*':
            token = Token('MULTIPLY', current_char)
            self.pos += 1
        elif current_char == '/':
            token = Token('DIVIDE', current_char)
            self.pos += 1
        elif current_char == '(':
            token = Token('LPAREN', current_char)
            self.pos += 1
        elif current_char == ')':
            token = Token('RPAREN', current_char)
            self.pos += 1
        else:
            self.error()

        return token

    def tokenize_number(self):
        result = ''
        while self.pos < len(self.text) and re.match(r'\d', self.text[self.pos]):
            result += self.text[self.pos]
            self.pos += 1
        return Token('NUMBER', int(result))

def main():
    text = input("Enter a mathematical expression: ")
    lexer = Lexer(text)

    while True:
        token = lexer.get_next_token()
        if token.type == 'EOF':
            break
        print(token)

if __name__ == '__main__':
    main()
