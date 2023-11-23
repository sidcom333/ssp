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

class Parser:
    def __init__(self, lexer):
        self.lexer = lexer
        self.current_token = self.lexer.get_next_token()

    def error(self):
        raise Exception('Invalid syntax')

    def eat(self, expected_type):
        if self.current_token.type == expected_type:
            self.current_token = self.lexer.get_next_token()
        else:
            self.error()

    def factor(self):
        token = self.current_token

        if token.type == 'NUMBER':
            self.eat('NUMBER')
            return token.value
        elif token.type == 'LPAREN':
            self.eat('LPAREN')
            result = self.expr()
            self.eat('RPAREN')
            return result
        else:
            self.error()

    def term(self):
        result = self.factor()

        while self.current_token.type in ['MULTIPLY', 'DIVIDE']:
            token = self.current_token
            if token.type == 'MULTIPLY':
                self.eat('MULTIPLY')
                result *= self.factor()
            elif token.type == 'DIVIDE':
                self.eat('DIVIDE')
                result /= self.factor()

        return result

    def expr(self):
        result = self.term()

        while self.current_token.type in ['PLUS', 'MINUS']:
            token = self.current_token
            if token.type == 'PLUS':
                self.eat('PLUS')
                result += self.term()
            elif token.type == 'MINUS':
                self.eat('MINUS')
                result -= self.term()

        return result

def main():
    text = input("Enter a mathematical expression: ")
    lexer = Lexer(text)
    parser = Parser(lexer)

    result = parser.expr()
    print("Result:", result)

if __name__ == '__main__':
    main()
