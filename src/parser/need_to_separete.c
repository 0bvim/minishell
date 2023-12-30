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
