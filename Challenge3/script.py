# Nouvelles valeurs des variables (8 octets chacune)
local_28 = 0x6730a39060b0d14
local_20 = 0x710672011d0c7106
local_18 = 0x3f

# Fonction pour extraire exactement 8 octets d'une valeur en little-endian
def extract_bytes(value, num_bytes=8):
    bytes_list = []
    for i in range(num_bytes):
        byte = (value >> (i * 8)) & 0xFF
        bytes_list.append(byte)
    return bytes_list

# Fonction pour désobfusquer le mot de passe
def deobfuscate_password(obfuscated_bytes):
    password_chars = []
    for byte in obfuscated_bytes:
        if byte == 0x00:  # Arrête la boucle si un octet nul est rencontré
            break
        password_chars.append(chr(byte ^ 0x42))  # XOR avec 0x42 pour révéler le caractère
    return ''.join(password_chars)

# Extraction des octets pour chaque variable, en combinant local_28, local_20 et local_18
obfuscated_password = extract_bytes(local_28) + extract_bytes(local_20) + extract_bytes(local_18, num_bytes=1)
password = deobfuscate_password(obfuscated_password)

print("Password:", password)
