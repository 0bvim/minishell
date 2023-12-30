void tokenizeSpaces(char* p, Token* tokens, int* numTokens) {
   while (*p == ' ' || *p == '\t' || *p == '\n') {
       p++;
   }
}

void tokenizeAnd(char* p, Token* tokens, int* numTokens) {
   if (*p == '&' && *(p + 1) == '&') {
       tokens[*numTokens].type = TOKEN_AND;
       tokens[*numTokens].value = "&&";
       (*numTokens)++;
       p += 2;
   }
}

void tokenizeOr(char* p, Token* tokens, int* numTokens) {
   if (*p == '|' && *(p + 1) == '|') {
       tokens[*numTokens].type = TOKEN_OR;
       tokens[*numTokens].value = "||";
       (*numTokens)++;
       p += 2;
   }
}

void tokenizeParentheses(char* p, Token* tokens, int* numTokens) {
   if (*p == '(') {
       tokens[*numTokens].type = TOKEN_LPAREN;
       tokens[*numTokens].value = "(";
       (*numTokens)++;
       p++;
   } else if (*p == ')') {
       tokens[*numTokens].type = TOKEN_RPAREN;
       tokens[*numTokens].value = ")";
       (*numTokens)++;
       p++;
   }
}

void tokenizeQuote(char* p, Token* tokens, int* numTokens) {
   if (*p == '"' || *p == '\'') {
       char quote = *p;
       char* begin = ++p;
       int quoteCount = 1;
       while (*p && quoteCount > 0) {
           if (*p == quote) quoteCount++;
           if (*p == quote) quoteCount--;
           p++;
       }
       if (quoteCount != 0) {
           // Handle error: unmatched quote
       }
       tokens[*numTokens].type = TOKEN_QUOTE;
       tokens[*numTokens].value = strndup(begin, p - begin);
       (*numTokens)++;
       p++;
   }
}

void tokenizeArgument(char* p, Token* tokens, int* numTokens) {
   char* begin = p;
   while (*p && !isspace(*p) && *p != '&' && *p != '|' && *p != '(' && *p != ')') p++;
   tokens[*numTokens].type = TOKEN_ARGUMENT;
   tokens[*numTokens].value = strndup(begin, p - begin);
   (*numTokens)++;
}

Token* tokenize(char* input) {
   char* p = input;
   Token* tokens = malloc(MAX_NUM_TOKENS * sizeof(Token));
   int numTokens = 0;

   while (*p != '\0') {
       tokenizeSpaces(p, tokens, &numTokens);
       tokenizeAnd(p, tokens, &numTokens);
       tokenizeOr(p, tokens, &numTokens);
       tokenizeParentheses(p, tokens, &numTokens);
       tokenizeQuote(p, tokens, &numTokens);
       tokenizeArgument(p, tokens, &numTokens);
   }

   return tokens;
}
