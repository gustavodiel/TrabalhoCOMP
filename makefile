
TEST_FILES=Exemplo1 Exemplo2 Exemplo3 Exemplo4 Exemplo5

run:
	@clear
	@echo "\n\033[0;35m============ \033[0;37m[ \033[0;33mPre-compiling \033[0;37m] \033[0;35m============ \n"
	@$(MAKE) compile
	@echo "\n\033[0;35m============ \033[0;37m[    \033[0;33mTesting    \033[0;37m] \033[0;35m============ \n"
	@$(MAKE) test

compile:
	@echo "\033[0;32mRunning \033[0;31mFlex\033[0;32m: \t \033[0;36mexpr.l\033[0;32m"
	@flex expr.l
	@echo "\033[0;32mRunning \033[0;31mBison\033[0;32m: \t \033[0;36mexpr.y\033[0;32m"
	@bison expr.y
	@echo "\n\033[0;35m============ \033[0;37m[   \033[0;33mCompiling   \033[0;37m] \033[0;35m============ \n"
	@echo "\033[0;32mCompiling \t \033[0;36mexpr.c"
	@sleep 0.05
	@echo "\033[0;32mCompiling \t \033[0;36mexpr.tab.c"
	@sleep 0.05
	@echo "\033[0;32mCompiling \t \033[0;36mMain.c"
	@sleep 0.05
	@echo "\033[0;32mCompiling \t \033[0;36mLista.c"
	@sleep 0.05
	@echo "\033[0;32mCompiling \t \033[0;36mListHandlers.c"
	@gcc expr.c expr.tab.c Main.c Lista.c ListHandlers.c -o compilador -Wno-implicit-function-declaration

test:
	@echo "\033[0;32mTesting \t \t \033[0;36mExemplo1.c\033[0;32m"
	@./compilador Exemplo1.c
	@echo "\033[1;36mSuccessful!\033[0;32m Outputed to\t \033[0;33mExemplo1.jout"
	@echo "\033[1;32mRunning \033[1;33mJasmin\033[1;35m"
	@jasmin Exemplo1.jout
	@echo "\033[1;32mRunning \033[1;33mJava Class\033[1;32m"
	@java Exemplo1

	@echo "\n"

	@echo "\033[0;32mTesting \t \t \033[0;36mExemplo2.c\033[0;32m"
	@./compilador Exemplo2.c
	@echo "\033[1;36mSuccessful!\033[0;32m Outputed to\t \033[0;33mExemplo2.jout"
	@echo "\033[1;32mRunning \033[1;33mJasmin\033[1;35m"
	@jasmin Exemplo2.jout
	@echo "\033[1;32mRunning \033[1;33mJava Class\033[1;32m"
	@java Exemplo2

	@echo "\n"

	@echo "\033[0;32mTesting \t \t \033[0;36mExemplo3.c\033[0;32m"
	@./compilador Exemplo3.c
	@echo "\033[1;36mSuccessful!\033[0;32m Outputed to\t \033[0;33mExemplo3.jout"
	@echo "\033[1;32mRunning \033[1;33mJasmin\033[1;35m"
	@jasmin Exemplo3.jout
	@echo "\033[1;32mRunning \033[1;33mJava Class\033[1;32m"
	@java Exemplo3

	@echo "\n"

	@echo "\033[0;32mTesting \t \t \033[0;36mExemplo4.c\033[0;32m"
	@./compilador Exemplo4.c
	@echo "\033[1;36mSuccessful!\033[0;32m Outputed to\t \033[0;33mExemplo4.jout"
	@echo "\033[1;32mRunning \033[1;33mJasmin\033[1;35m"
	@jasmin Exemplo4.jout
	@echo "\033[1;32mRunning \033[1;33mJava Class\033[1;32m"
	@java Exemplo4

clean:
	@rm -f compilador *.jout *.class

rights:
	@echo "By Filipe, Gustavo and Paula"

Black="\[\033[0;30m\]"        # Black
Red="\[\033[0;31m\]"          # Red
Green="\[\033[0;32m\]"        # Green
Yellow="\[\033[0;33m\]"       # Yellow
Blue="\[\033[0;34m\]"         # Blue
Purple="\[\033[0;35m\]"       # Purple
Cyan="\[\033[0;36m\]"         # Cyan
White="\[\033[0;37m\]"        # White
