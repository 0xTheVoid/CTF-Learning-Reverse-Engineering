# 🏆 Challenge Write-up: Binary Analysis Basics 🏆

This challenge is designed to focus on binary analysis fundamentals, highlighting the importance of examining the binary directly when other tools don't yield immediate results.

## Challenge Overview

- **Objective:** Find the hidden flag within a binary file.
- **Difficulty:** Beginner
- **Tools Required:** 
  - ghex (or any hex editor)
  - Basic understanding of binary data structures

## Step-by-Step Solution

### Step 1: Running the Program

When you execute the program, it displays two sentences, with no other apparent interaction or input required. This output may seem like a dead end, but it’s the first indication that the solution might be hidden within the binary itself.

### Step 2: Using `strings` Command

To start the analysis, try running `strings` on the binary:

    strings <program_name>

**Result:** `strings` does not return any interesting or useful output in this case. The flag is not stored as plain text within the binary, so we’ll need to dig deeper.

### Step 3: Trying `ltrace` and `strace`

Next, let's see if `ltrace` or `strace` provides any insights into the program's function calls or system interactions:

- **ltrace** shows us the library calls, which can help in identifying functions like printf, strcmp, fgets, etc.
  
      ltrace ./<program_name>

- **strace** logs system calls and signals, giving clues if the program interacts with files, networks, or other system resources.

      strace ./<program_name>

**Result:** Both `ltrace` and `strace` fail to yield any useful information for this challenge. The program appears to be simple and does not make any significant library or system calls related to the flag.

### Step 4: Analyzing the Binary with `ghex`

Since the above tools didn’t give us the flag, it’s time to examine the binary directly using a hex editor like ghex.

1. **Open the Binary in ghex:**

       ghex <program_name>
   
2. **Searching for the Flag Pattern:**
   
   In ghex, scroll through the hex data and look for any readable ASCII characters that might resemble a flag. In this challenge, the flag is embedded in the binary, but it’s spread across different bytes at regular intervals.

   **Hint:** In CTF challenges, flags are often hidden by separating each character of the flag with padding bytes, making it harder to detect with strings.

3. **Identifying the Flag in ghex:**
   
   As you scroll, you should see a pattern of characters spaced across multiple bytes, resembling this:

       4C 00 00 47 00 00 48 00 00 7B 00 00 4C 00 00 45 ...

   Converting this hex to ASCII, you’ll notice that every third byte is part of a readable sequence, forming the following flag:

       VOID{D3LV3INTO_C0D3}

### Step 5: Extracting the Flag

By reading only the relevant bytes and ignoring the padding bytes (00), you can reconstruct the flag as follows:

**Flag: `VOID{D3LV3INTO_C0D3}`**

---

## Conclusion

This challenge demonstrates the importance of analyzing the binary directly when common tools like strings, ltrace, and strace don’t reveal useful information. It’s a reminder that flags can be hidden in unconventional ways, such as by spacing out characters with padding bytes.

### Key Takeaways
- Don’t rely solely on strings, ltrace, or strace. They’re useful, but not foolproof.
- Examining the binary in a hex editor like ghex can reveal hidden patterns, especially in CTF challenges where flags are obfuscated with spacing.
- Look for readable patterns at regular intervals when you suspect a flag is hidden in the binary itself.

Good luck with your future binary analysis challenges, and remember: sometimes, the simplest tools can yield the most insights! 🔍








# 🏆 Guide de Résolution : Analyse de Binaire de Base 🏆

Ce challenge est conçu pour se concentrer sur les fondamentaux de l'analyse de binaire, mettant en avant l'importance d'examiner directement le binaire lorsque les autres outils ne donnent pas de résultats immédiats.

## Présentation du Challenge

- **Objectif :** Trouver le flag caché dans un fichier binaire.
- **Difficulté :** Débutant
- **Outils Requis :** 
  - ghex (ou un autre éditeur hexadécimal)
  - Connaissances de base en structures de données binaires

## Solution Étape par Étape

### Étape 1 : Exécuter le Programme

Lorsqu’on exécute le programme, il affiche deux phrases sans autre interaction ou entrée requise. Cela peut sembler une impasse, mais c’est la première indication que la solution pourrait être cachée dans le binaire lui-même.

### Étape 2 : Utiliser la Commande `strings`

Pour commencer l'analyse, essayez d'exécuter `strings` sur le binaire :

    strings <nom_du_programme>

**Résultat :** `strings` ne retourne rien d'intéressant ou d'utile dans ce cas. Le flag n'est pas stocké en texte clair dans le binaire, donc nous devons approfondir l'analyse.

### Étape 3 : Essayer `ltrace` et `strace`

Ensuite, voyons si `ltrace` ou `strace` nous donnent des informations sur les appels de fonctions ou les interactions système du programme :

- **ltrace** affiche les appels aux bibliothèques, ce qui peut aider à identifier des fonctions comme printf, strcmp, fgets, etc.
  
      ltrace ./<nom_du_programme>

- **strace** enregistre les appels système et les signaux, ce qui peut donner des indices si le programme interagit avec des fichiers, des réseaux ou d'autres ressources système.

      strace ./<nom_du_programme>

**Résultat :** Ni `ltrace` ni `strace` ne donnent d’informations utiles pour ce challenge. Le programme semble être simple et ne fait aucun appel significatif aux bibliothèques ou au système en rapport avec le flag.

### Étape 4 : Analyser le Binaire avec `ghex`

Étant donné que les outils précédents n'ont pas révélé le flag, il est temps d'examiner directement le binaire en utilisant un éditeur hexadécimal comme `ghex`.

1. **Ouvrir le Binaire dans ghex :**

       ghex <nom_du_programme>
   
2. **Rechercher le Motif du Flag :**
   
   Dans `ghex`, parcourez les données hexadécimales et recherchez tout caractère ASCII lisible qui pourrait ressembler à un flag. Dans ce challenge, le flag est intégré dans le binaire, mais il est réparti sur différents octets à intervalles réguliers.

   **Indice :** Dans les challenges CTF, les flags sont souvent cachés en séparant chaque caractère du flag par des octets de remplissage, rendant leur détection difficile avec `strings`.

3. **Identifier le Flag dans ghex :**
   
   En faisant défiler, vous devriez voir un motif de caractères espacés sur plusieurs octets, ressemblant à ceci :

       4C 00 00 47 00 00 48 00 00 7B 00 00 4C 00 00 45 ...

   En convertissant cet hexadécimal en ASCII, vous remarquerez que chaque troisième octet fait partie d’une séquence lisible, formant le flag suivant :

       VOID{D3LV3INTO_C0D3}

### Étape 5 : Extraire le Flag

En lisant uniquement les octets pertinents et en ignorant les octets de remplissage (`00`), vous pouvez reconstituer le flag comme suit :

**Flag :** `VOID{D3LV3INTO_C0D3}`

---

## Conclusion

Ce challenge démontre l'importance d'analyser directement le binaire lorsque des outils courants comme `strings`, `ltrace` et `strace` ne révèlent pas d’informations utiles. Cela rappelle que les flags peuvent être cachés de manière non conventionnelle, par exemple en espaçant les caractères avec des octets de remplissage.

### Points Clés
- Ne vous fiez pas uniquement à `strings`, `ltrace` ou `strace`. Ils sont utiles, mais pas infaillibles.
- Examiner le binaire dans un éditeur hexadécimal comme `ghex` peut révéler des motifs cachés, surtout dans les challenges CTF où les flags sont obfusqués par espacement.
- Recherchez des motifs lisibles à intervalles réguliers si vous soupçonnez qu’un flag est caché dans le binaire lui-même.

Bonne chance pour vos prochains challenges d'analyse de binaire, et rappelez-vous : parfois, les outils les plus simples peuvent fournir les meilleurs indices ! 🔍
