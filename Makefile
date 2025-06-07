BINARY=lalgc
TEST=ex/ex0.lalg
CC=gcc

flex: lexer.l
	@flex lexer.l
yacc: flex parser.y
	@yacc -d parser.y
all: yacc
	@$(CC) lex.yy.c y.tab.c -o $(BINARY)
clean:
	@rm -f y.tab.c y.tab.h lex.yy.c $(BINARY)
	@rm -rf output
test: $(BINARY)
	@# Detect Unicode support
	@if locale | grep -q 'UTF-8'; then \
		PASS_SYMBOL="✅"; FAIL_SYMBOL="❌"; \
	else \
		PASS_SYMBOL="[ OK ]"; FAIL_SYMBOL="[FAIL]"; \
	fi; \
	passed=0; failed=0; \
	for i in 0 1 2 3 4 5 6 7; do \
		output=$$(./$(BINARY) -i ex/ex$$i.lalg 2>&1); \
		if echo "$$output" | grep -qi 'erro'; then \
			echo "$$FAIL_SYMBOL ERROR in ex$$i.lalg:"; \
			echo "$$output"; \
			failed=$$((failed + 1)); \
		else \
			echo "$$PASS_SYMBOL PASSED: ex$$i.lalg (no errors)"; \
			passed=$$((passed + 1)); \
		fi; \
	done; \
	echo ""; \
	echo "$$PASS_SYMBOL Total Passed: $$passed"; \
	echo "$$FAIL_SYMBOL Total Failed: $$failed"; \
	test $$failed -eq 0

test-output: $(BINARY)
	@mkdir -p output
	@# Detect Unicode support
	@if locale | grep -q 'UTF-8'; then \
		PASS_SYMBOL="✅"; FAIL_SYMBOL="❌"; \
	else \
		PASS_SYMBOL="[ OK ]"; FAIL_SYMBOL="[FAIL]"; \
	fi; \
	passed=0; failed=0; \
	for i in 0 1 2 3 4 5 6 7; do \
		output=$$(./$(BINARY) -i ex/ex$$i.lalg -t output/out$$i.ast >output/out$$i.log 2>&1); \
		if cat output/out$$i.log | grep -qi 'erro'; then \
			echo "$$FAIL_SYMBOL UNEXPECTED ERROR in ex/ex$$i.lalg:"; \
			cat output/out$$i.log; \
			failed=$$((failed + 1)); \
		else \
			echo "$$PASS_SYMBOL PASSED: ex/ex$$i.lalg → output/out$$i.ast"; \
			passed=$$((passed + 1)); \
		fi; \
	done; \
	echo ""; \
	echo "$$PASS_SYMBOL Total Passed: $$passed"; \
	echo "$$FAIL_SYMBOL Total Failed: $$failed"; \
	test $$failed -eq 0