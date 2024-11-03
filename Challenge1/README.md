# 🏛️ Challenge Write-up: Temple 🏛️

"Temple" is an extremely simple reverse engineering challenge, designed to help beginners understand basic binary behavior and analysis.

## Challenge Overview

- **Objective:** Find the hidden flag within the program.
- **Difficulty:** Beginner
- **Tools Required:** 
  - `file` command
  - Ghidra (or another disassembler)

## Step-by-Step Solution

### Step 1: Analyzing the File with `file`

To begin, check the file type using the `file` command to get basic information about the binary.

    file <program_name>

This will give you an overview of the binary format, which helps in understanding the context (e.g., whether it’s a 32-bit or 64-bit ELF binary).

### Step 2: Setting Up the Project in Ghidra

1. **Create a New Project**: Open Ghidra and create a new project.
2. **Import the Binary**: Import the program into your Ghidra project.
3. **Analyze the Binary**: Run the analysis to help Ghidra identify functions, variables, and structures within the binary.

### Step 3: Searching for Strings

Use the **Strings** tool in Ghidra to quickly find any readable text in the binary. In many beginner challenges, flags or hints are stored as strings and can be found by simply viewing the strings in the binary.

In this case, you should be able to locate the flag directly within the strings section.

### Step 4: Extracting the Flag

The flag is located as a readable string within the binary:

**Flag: `VOID{D1sc0v3r_Th3_Unkn0wn_C0d3}`**

---

## Conclusion

The "Temple" challenge is straightforward and is perfect for beginners who are learning to use basic reverse engineering tools like `file` and Ghidra. It emphasizes the importance of examining strings within a binary, as flags in beginner challenges are often embedded as readable text.

### Key Takeaways
- Use `file` to gather information about the binary format.
- Familiarize yourself with Ghidra’s project setup and analysis tools.
- Checking for strings in a binary is a useful starting point in many CTF challenges.

Good luck, and enjoy the journey into reverse engineering! 🕵️‍♂️

---

---

# 🏛️ Guide de Résolution : Temple 🏛️

"Temple" est un challenge de reverse engineering très simple, conçu pour aider les débutants à comprendre le comportement de base d'un binaire et les premières étapes de son analyse.

## Présentation du Challenge

- **Objectif :** Trouver le flag caché dans le programme.
- **Difficulté :** Débutant
- **Outils Requis :** 
  - Commande `file`
  - Ghidra (ou un autre désassembleur)

## Solution Étape par Étape

### Étape 1 : Analyser le Fichier avec `file`

Pour commencer, vérifiez le type de fichier avec la commande `file` pour obtenir des informations de base sur le binaire.

    file <nom_du_programme>

Cela vous donnera un aperçu du format du binaire, ce qui aide à comprendre le contexte (par exemple, s'il s'agit d'un binaire ELF 32 bits ou 64 bits).

### Étape 2 : Configurer le Projet dans Ghidra

1. **Créer un Nouveau Projet** : Ouvrez Ghidra et créez un nouveau projet.
2. **Importer le Binaire** : Importez le programme dans votre projet Ghidra.
3. **Analyser le Binaire** : Lancez l’analyse pour aider Ghidra à identifier les fonctions, les variables et les structures du binaire.

### Étape 3 : Rechercher les Chaînes de Caractères

Utilisez l'outil **Strings** dans Ghidra pour trouver rapidement tout texte lisible dans le binaire. Dans de nombreux challenges pour débutants, les flags ou indices sont stockés sous forme de chaînes de caractères lisibles et peuvent être trouvés en visualisant simplement les chaînes dans le binaire.

Dans ce cas, vous devriez être en mesure de localiser le flag directement dans la section des chaînes de caractères.

### Étape 4 : Extraire le Flag

Le flag est situé sous forme de chaîne de caractères lisible dans le binaire :

**Flag : `VOID{D1sc0v3r_Th3_Unkn0wn_C0d3}`**

---

## Conclusion

Le challenge "Temple" est simple et parfait pour les débutants qui apprennent à utiliser des outils de base en reverse engineering comme `file` et Ghidra. Il met en avant l'importance de vérifier les chaînes de caractères dans un binaire, car les flags des challenges pour débutants sont souvent intégrés sous forme de texte lisible.

### Points Clés
- Utilisez `file` pour recueillir des informations sur le format du binaire.
- Familiarisez-vous avec la configuration de projet et les outils d’analyse de Ghidra.
- Vérifier les chaînes de caractères dans un binaire est souvent une bonne première étape dans de nombreux challenges CTF.

Bonne chance, et profitez de votre exploration dans le reverse engineering ! 🕵️‍♂️
