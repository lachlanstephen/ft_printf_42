<h1>ft_printf</h1>

<h3>Mark: 100/100</h3>

<p><i>Note</i>: I'm currently working on the bonuses, so this repo wouldn't be able to be submitted as is.</p>

<p>ft_printf, one of three projects in Ring 1 of the 42 Cursus, introduced us to the idea of variadic functions, as in functions that take in a variable amount of arguments.</p>

<p>Our task was to write a library that contains a recreation of printf from <stdio.h> in the Standard C Library</p>

<p>The project requirements:</p>

<ul>
<li>Don't implement original printf buffer management</li>
<li>Handle the conversions `cspdiuxX%`</li>
<li>Output will be compared to original printf()</li>
</ul>

<p>Bonus requirements:</p>

<ul>
<li>Manage a combination of the flags `-0.` and field minimum width</li>
<li>Mange flags `# +`</li>
</ul>

<h3>Testing ft_printf functions</h3>

To test your own ft_printf, download [`main.c`](./ft_printf/main.c) and [`testing_Makefile`](./ft_printf/testing_Makefile) files from my repo, and move into your ft_printf project folder.

<p>Run these commands to test your ft_printf functionality:</p>

```bash

# Make using the specific Makefile with the -f flag

make re -f testing_Makefile

# Run compiled program

./test_printf
```
<p>Compare the user output with the expected output.</p>

**_Important_: Make sure to run `make fclean -f testing_Makefile` to clean up files before submitting for evaluation.**

<h3>Future Use of ft_printf</h3>

<p>ft_printf can be added to your libft project folder to be used in future projects</p>

<h4>Plan for repository</h4>

- [ ] Complete bonus flag functionality
- [ ] Re-evaluate project with bonuses
- [ ] Return whether diff of output is same or different

