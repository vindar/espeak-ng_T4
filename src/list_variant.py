from pathlib import Path

def main():
    # Demander le chemin du répertoire
    folder = input("Entrez le chemin du dossier contenant les .h (relatif ou absolu) : ").strip()
    directory = Path(folder).expanduser().resolve()

    # Vérifier l'existence du dossier
    if not directory.exists() or not directory.is_dir():
        print(f"Erreur : le dossier '{directory}' n'existe pas.")
        return

    # Lister les fichiers .h
    headers = sorted([f for f in directory.glob("*.h") if f.is_file()])
    if not headers:
        print(f"Aucun fichier .h trouvé dans {directory}")
        return

    # Générer le contenu du fichier .cpp
    includes = [f'#include "{f.name}"' for f in headers]
    registrations = [f'    ESPEAK_REGISTER_VARIANT({f.stem})' for f in headers]

    content = "\n".join(includes)
    content += "\n\nvoid addVariants()\n{\n"
    content += "\n".join(registrations)
    content += "\n}\n\n/** end of file */\n"

    # Écriture dans un fichier cpp
    output_file = directory / "add_variants.cpp"
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(content)

    print(f"✅ Fichier généré : {output_file}")

if __name__ == "__main__":
    main()
