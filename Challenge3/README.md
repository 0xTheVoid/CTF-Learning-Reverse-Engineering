# 🔐 Challenge Write-up: The Last Words of the Legendary Hacker 🔐

In this challenge, you’ll be tasked with bypassing a password check in the program to reveal the hidden message left by a legendary hacker. This exercise focuses on understanding binary behavior, de-obfuscation, and working with Ghidra.

## Challenge Overview

- **Objective:** Retrieve the hidden password and bypass the check to display the secret message.
- **Difficulty:** Intermediate
- **Tools Required:** 
  - Ghidra (for disassembly and decompilation)
  - Python (for scripting and de-obfuscation)

## Step-by-Step Solution

### Step 1: Running the Program

When you execute the program, it prompts for a password. If you enter an incorrect password, the program displays an error message and exits. This indicates that there is a specific password we need to input to unlock the secret message.

### Step 2: Using `strings`

Running `strings` on the binary reveals nothing useful. The password is likely obfuscated and needs to be extracted by analyzing the binary code directly.

Command:

    strings <binary_name>

### Step 3: Opening the Program in Ghidra

1. **Create a New Project**: Open Ghidra, create a new project, and import the binary.
2. **Analyze the Program**: Run an analysis to help Ghidra identify functions and structures in the binary.
3. **Inspecting the `main` Function**: In the `main` function, we observe that it calls a function named `check_code`, which likely verifies the entered password.

### Step 4: Analyzing the `check_code` Function

In the `check_code` function, we notice three key variables:
- `local_28` initialized to `0x6730a39060b0d14`
- `local_20` initialized to `0x710672011d0c7106`
- `local_18` initialized to `0x3f`

The code iterates over each character, verifying the user input byte by byte with an obfuscated password by XORing each byte with `0x42`. If the comparison matches the obfuscated password, the check passes; otherwise, it fails.

### Step 5: Writing a Python Script for De-obfuscation

The variables `local_28` and `local_20` are 8 bytes each, while `local_18` is 1 byte. We’ll use these to reconstruct the obfuscated password.

#### Step 5.1: Define Base Variables

    local_28 = 0x6730a39060b0d14
    local_20 = 0x710672011d0c7106
    local_18 = 0x3f

#### Step 5.2: Extracting Bytes from the Variables

Define a function to extract individual bytes from `local_28`, `local_20`, and `local_18`:

    def extract_bytes(value, num_bytes=8):
        bytes_list = []
        for i in range(num_bytes):
            byte = (value >> (i * 8)) & 0xFF
            bytes_list.append(byte)
        return bytes_list

Using this function, extract the bytes from `local_28`, `local_20`, and `local_18`, then combine them to reconstruct the obfuscated password.

#### Step 5.3: De-obfuscating the Password

The password is XORed with `0x42`, so we can reverse the obfuscation by XORing each byte with `0x42`. This reveals the actual password.

    def deobfuscate_password(obfuscated_bytes):
        password_chars = []
        for byte in obfuscated_bytes:
            if byte == 0x00:
                break
            password_chars.append(chr(byte ^ 0x42))
        return ''.join(password_chars)

#### Step 5.4: Running the Script

Combine the extracted bytes and deobfuscate them:

    obfuscated_password = extract_bytes(local_28) + extract_bytes(local_20) + extract_bytes(local_18, num_bytes=1)
    password = deobfuscate_password(obfuscated_password)

The output reveals the password:

**Password:** `VOID{H1DD3N_C0D3}`

### Step 6: Entering the Password in the Program

Run the program again and enter the password `VOID{H1DD3N_C0D3}` to reveal the hidden message:

    Access granted!
    Here are the final words of the legendary hacker:
    "Sometimes, what you seek is hidden in the shadows..."

---

## Conclusion

This challenge demonstrates the process of analyzing a binary, extracting obfuscated data, and using scripting to reverse engineer the password. It’s a great way to practice working with XOR obfuscation and understand the flow of binary analysis in Ghidra.

### Key Takeaways
- Ghidra is useful for analyzing functions, understanding the structure of a program, and examining obfuscated data.
- XOR obfuscation is common in CTF challenges, and it can be reversed if the XOR key is known.
- Python scripting is a powerful tool to automate de-obfuscation and byte extraction.

Good luck, and remember: sometimes, the secrets are hidden in plain sight! 🔍

---
---

# 🔐 Guide de Résolution : Les Derniers Mots du Légendaire Hacker 🔐

Dans ce challenge, vous devez contourner une vérification de mot de passe dans le programme pour révéler le message caché laissé par un hacker légendaire. Cet exercice se concentre sur la compréhension du comportement binaire, la désobfuscation, et l'utilisation de Ghidra.

## Présentation du Challenge

- **Objectif :** Récupérer le mot de passe caché et contourner la vérification pour afficher le message secret.
- **Difficulté :** Intermédiaire
- **Outils Requis :** 
  - Ghidra (pour la désassemblage et la décompilation)
  - Python (pour le script de désobfuscation)

## Solution Étape par Étape

### Étape 1 : Exécuter le Programme

Lors de l'exécution du programme, il demande un mot de passe. Si un mot de passe incorrect est entré, le programme affiche un message d'erreur et se ferme. Cela indique qu'il y a un mot de passe spécifique à entrer pour débloquer le message caché.

### Étape 2 : Utiliser `strings`

En exécutant `strings` sur le binaire, aucun résultat utile n'est affiché. Le mot de passe est probablement obfusqué et doit être extrait en analysant directement le code binaire.

Commande :

    strings <nom_du_binaire>

### Étape 3 : Ouvrir le Programme dans Ghidra

1. **Créer un Nouveau Projet** : Ouvrez Ghidra, créez un nouveau projet et importez le binaire.
2. **Analyser le Programme** : Lancez une analyse pour aider Ghidra à identifier les fonctions et les structures du binaire.
3. **Inspection de la Fonction `main`** : Dans la fonction `main`, on observe qu'elle appelle une fonction nommée `check_code`, qui semble vérifier le mot de passe entré.

### Étape 4 : Analyser la Fonction `check_code`

Dans la fonction `check_code`, on remarque trois variables clés :
- `local_28` initialisée à `0x6730a39060b0d14`
- `local_20` initialisée à `0x710672011d0c7106`
- `local_18` initialisée à `0x3f`

Le code compare chaque caractère en utilisant un XOR avec `0x42` sur chaque octet du mot de passe entré. Si le résultat correspond au mot de passe obfusqué, la vérification est validée ; sinon, elle échoue.

### Étape 5 : Écrire un Script pour Désobfusquer le Mot de Passe

Les variables `local_28` et `local_20` contiennent chacune 8 octets, tandis que `local_18` en contient un seul. Nous utiliserons ces valeurs pour reconstruire le mot de passe obfusqué.

#### Étape 5.1 : Définir les Variables de Base

    local_28 = 0x6730a39060b0d14
    local_20 = 0x710672011d0c7106
    local_18 = 0x3f

#### Étape 5.2 : Extraire les Octets des Variables

Définissez une fonction pour extraire les octets de `local_28`, `local_20`, et `local_18`.

    def extract_bytes(value, num_bytes=8):
        bytes_list = []
        for i in range(num_bytes):
            byte = (value >> (i * 8)) & 0xFF
            bytes_list.append(byte)
        return bytes_list

Utilisez cette fonction pour extraire les octets de `local_28`, `local_20` et `local_18`, puis combinez-les pour reconstituer le mot de passe obfusqué.

#### Étape 5.3 : Désobfusquer le Mot de Passe

Le mot de passe est XORé avec `0x42`, donc on peut inverser l'obfuscation en XORant chaque octet avec `0x42`. Cela révèle le mot de passe original.

    def deobfuscate_password(obfuscated_bytes):
        password_chars = []
        for byte in obfuscated_bytes:
            if byte == 0x00:
                break
            password_chars.append(chr(byte ^ 0x42))
        return ''.join(password_chars)

#### Étape 5.4 : Exécuter le Script

Combinez les octets extraits et désobfusquez-les.

    obfuscated_password = extract_bytes(local_28) + extract_bytes(local_20) + extract_bytes(local_18, num_bytes=1)
    password = deobfuscate_password(obfuscated_password)

Le mot de passe révélé est :

**Mot de passe :** `VOID{H1DD3N_C0D3}`

### Étape 6 : Entrer le Mot de Passe dans le Programme

Exécutez de nouveau le programme et entrez le mot de passe `VOID{H1DD3N_C0D3}` pour révéler le message caché :

    Access granted!
    Here are the final words of the legendary hacker:
    "Sometimes, what you seek is hidden in the shadows..."

---

## Conclusion

Ce challenge montre comment analyser un binaire, extraire des données obfusquées et utiliser un script pour faire du reverse engineering sur le mot de passe. C'est un bon moyen de s'entraîner à travailler avec l'obfuscation XOR et à comprendre le flux d'analyse binaire dans Ghidra.

### Points Clés

- Ghidra est utile pour analyser les fonctions, comprendre la structure d'un programme, et examiner les données obfusquées.
- L'obfuscation XOR est courante dans les challenges CTF, et elle peut être inversée si la clé XOR est connue.
- Un script Python est un outil puissant pour automatiser la désobfuscation et l'extraction d'octets.

Bonne chance, et souvenez-vous : parfois, les secrets sont cachés en pleine vue ! 🔍

