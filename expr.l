delim   [ \t\n]
ws  {delim}+
digito  [0-9]
letra [A-Za-z]
num {digito}+
id ({letra}|\_)+({letra}|{digito}|\_)*
literal \"(\\.|[^"])*\"

%%
{ws}    {}
"String" {return TSTRING;}
"void" {return TVOID;}
"int" {return TINT;}
"return" {return TRETURN;}
"print" {return TPRINT;}
"read" {return TREAD;}
"if" {return TIF;}
"while" {return TWHILE;}
"else" {return TELSE;}
"!=" {return TDIFER;} 
"==" {return TIGUAL;}
"!" {return TNOT;}
"&&" {return TAND;}
"||" {return TOR;}
"<=" {return TMEIGUAL;}
">=" {return TMAIGUAL;} 
"=" {return TATRIB;}
">" {return TMAIOR;}
"<" {return TMENOR;}
"{" {return TACHAVE;}
"}" {return TFCHAVE;}
"+=" {return TINC_N;}
"-=" {return TDEC_N;}
"++" {return TINC;}
"--" {return TDEC;}
"+" {return TADD;}
"-" {return TSUB;}
"*" {return TMUL;}
"/" {return TDIV;}
"(" {return TAPAR;}
")" {return TFPAR;}
"," {return TVIRG;}
";" {return TPVIRG;}
{id} {strcpy(yylval.id, yytext); return TID;}
{literal} {strcpy(yylval.literal, yytext); return TLITERAL;}
{num} {yylval.constante = atoi(yytext); return TNUM;}
. {return TERROR;}
