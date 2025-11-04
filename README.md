# 42-Push_swap 📦
![Push_swap AI Photo](https://github.com/user-attachments/assets/cd5138a1-4bfc-4a4a-9fb8-44868c071d38)

**Introduction:**
🧠 Writing a **sorting algorithm** is always a crucial step in a developer’s journey. It is often the first encounter with the concept of complexity. 

📈 Sorting algorithms and their complexities are common topics in job interviews. 

🚀 The learning objectives of this project are rigor, proficiency in C, and the application of basic algorithms, with a particular focus on their complexity. 🔍 Sorting values is straightforward, but finding the fastest way to sort them is more challenging. 🧩 The most efficient sorting method can vary depending on the arrangement of integers.

**Goal:**
🎯 Write a program called `push_swap` that calculates and shows the smallest sequence of `push_swap` instructions needed to sort the given integers, thus reordering stack `a` (stack `b` is only used to move numbers around).

---

### 📦 Context:

2 stacks called `a` and `b`.

* `a` contains random negative and/or positive integers.
* `b` is empty.

To sort them using stack `b` you have the following operations:

* `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
* `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
* `ss`: `sa` and `sb` at the same time.
* `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
* `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
* `ra` (rotate a): Shift up all elements of stack `a` by 1. The first element becomes the last one. ⬆️
* `rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one. ⬆️
* `rr`: `ra` and `rb` at the same time.
* `rra` (reverse rotate a): Shift down all elements of stack `a` by 1. The last element becomes the first one. ⬇️
* `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one. ⬇️
* `rrr`: `rra` and `rrb` at the same time.

---

We are given an example where 6 numbers are in stack `a` and are sorted in stack `a` in 12 instructions.
Surely it can be done better, so without reading instructions or solutions,  I started to think about how I could solve it.

I began by trying to divide it into smaller subproblems using various steps:

### Step 1️⃣ The program must determine the order in which the numbers should be sorted.

Very simple, just a while loop that step by step fills a list.

### Step 2️⃣ Evaluate the situations:

**Premise:**

At first, I tried evaluating the possible scenarios (numbers already sorted, reversed, 2 consecutive numbers sorted and the rest scrambled) but it wasn’t very useful. So I thought of sorting based on the number of input elements, that is, the number of elements in stack `a` before sorting begins, which for convenience I called `n`.

These are the possible situations:

* No input argument (`n = 0`) → Edge case: nothing should be returned and the prompt must be restored.

* `n = 1`: zero moves needed, `a` is already sorted.

* `n = 2`: two possibilities:

  * lowest number on top → zero moves needed, `a` is already sorted
  * highest number on top → one move needed: move = `sa`

* `n = 3`:

  * numbers sorted → no problem
  * numbers in reverse order → 4 moves needed: `ra`, `ra`, `sa`, `ra` (note: this isn’t the best combination, but I didn’t know it yet)
  * first two out of order, last correct → 1 move needed: `sa`
  * first correct, last two out of order →

I continued this way until completing the solutions for `n = 3`, but since `n = 4` would already have `4!` possible combinations (that is, 24 possibilities), I realized I needed to find another method.

I searched for READMEs from people who had already completed the project. I stumbled upon the repo by `ayogun` and especially his Medium article "Push Swap — A journey to find most efficient sorting algorithm" (insert link).

One of the algorithms to solve the problem is called **Radix Sort**, but the author of the article used his own, which he ironically called the **Turk Algorithm** because according to him it is not very elegant and is hard-coded.

### 🤖 L'algoritmo del "Turk"

L'idea dietro al metodo "Turk" è sorprendentemente lineare, e segue tre passaggi ricorrenti:

**Fase 1 – Riempire `stack_b`:**
spostiamo gli elementi da `stack_a` a `stack_b`, scegliendo ogni volta quello che può essere pushato nel punto giusto con il minor numero di mosse. In questo modo `stack_b` prende forma in ordine decrescente mentre `a` si svuota progressivamente.

**Fase 2 – Sistemare il cuore dell'ordinamento:**
quando in `stack_a` rimangono soltanto tre valori, li ordiniamo direttamente lì (niente giri inutili in `stack_b`). Subito dopo, riprendiamo gli elementi di `stack_b` e li riposizioniamo in `stack_a`, calcolando di volta in volta la combinazione di rotazioni più economica. Così l'array principale torna a crescere già in ordine crescente.

**Fase 3 – L'ultima rifinitura:**
se necessario, eseguiamo un'ultima rotazione di `stack_a` per riportare il minimo assoluto in cima. È l'equivalente di dare l'ultimo tocco a un domino perfettamente allineato.

📌 **Risultato finale:** `stack_a` è perfettamente ordinato in senso crescente e `stack_b` torna vuoto, a conferma che ogni spostamento è stato pianificato per minimizzare il numero complessivo di operazioni.

Vediamo ora il flusso del codice.

