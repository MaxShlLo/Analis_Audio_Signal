import os
import sys

LKF_PATH = "src/practice1.lkf"
SRC_DIR = "src"
MODE = "run"
if len(sys.argv) > 1:
    MODE = sys.argv[1].lower()

def get_object_files():
    obj_files = []
    for file in os.listdir(SRC_DIR):
        # Пропускаємо файл векторів, щоб він не дублювався у загальному списку!
        if file.endswith(".c") and file != "stm8_interrupt_vector.c":
            obj_name = file.replace(".c", ".o")
            obj_path = os.path.join(SRC_DIR, obj_name)  
            obj_files.append(obj_path.replace("/", "\\"))
    return obj_files

def generate_lkf(object_files):
    lkf = []

    # Сегменты
    lkf.append("+seg .const -b 0x8080 -m 0x1f80  -n .const -it ")
    lkf.append("+seg .text -a .const  -n .text ")
    lkf.append("")
    lkf.append("+seg .eeprom -b 0x4000 -m 0x280  -n .eeprom ")
    lkf.append("")
    lkf.append("+seg .bsct -b 0x0 -m 0x100  -n .bsct ")
    lkf.append("+seg .ubsct -a .bsct  -n .ubsct ")
    lkf.append("+seg .bit -a .ubsct  -n .bit -id ")
    lkf.append("+seg .share -a .bit  -n .share -is ")
    lkf.append("")
    # Збільшена пам'ять для FFT масивів (639 байт)
    lkf.append("+seg .data -b 0x100 -m 0x2BF  -n .data ")
    lkf.append("+seg .bss -a .data  -n .bss ")
    lkf.append("")

    # Startup файл
    lkf.append("#<BEGIN STARTUP_FILE>")
    lkf.append(r'"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\lib\crtsi0.sm8"')
    lkf.append("#<END STARTUP_FILE>")
    lkf.append("")

    # Object файлы
    lkf.append("#<BEGIN OBJECT_FILES>")
    for obj in object_files:
        lkf.append(obj)
    lkf.append("#<END OBJECT_FILES>")
    lkf.append("")

    # Библиотеки
    lkf.append("#<BEGIN LIBRARY_FILES>")
    lkf.append(r'"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\lib\libis0.sm8"')
    lkf.append(r'"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\lib\libm0.sm8"')
    lkf.append("#<END LIBRARY_FILES>")
    lkf.append("")

    # Векторы
    lkf.append("#<BEGIN VECTOR_FILE>")
    lkf.append("+seg .const -b 0x8000 -k")
    if MODE == "debug":
        # ГОЛОВНЕ ВИПРАВЛЕННЯ: прибрано '#'
        lkf.append(r"Debug\stm8_interrupt_vector.o")
    else:
        # ГОЛОВНЕ ВИПРАВЛЕННЯ: прибрано '#'
        lkf.append(r"src\stm8_interrupt_vector.o")
    lkf.append("#<END VECTOR_FILE>")
    lkf.append("")

    # Defines
    lkf.append("#<BEGIN DEFINED_VARIABLES>")
    lkf.append("+def __endzp=@.ubsct\t\t\t# end of uninitialized zpage")
    lkf.append("+def __memory=@.bss\t\t\t# end of bss segment")
    lkf.append("+def __startmem=@.bss")
    # Оновлений ліміт пам'яті для масивів
    lkf.append("+def __endmem=0x3Bf")
    lkf.append("+def __stack=0x3ff")
    lkf.append("#<END DEFINED_VARIABLES>")

    return "\n".join(lkf)

def main():
    object_files = get_object_files()

    lkf_text = generate_lkf(object_files)

    with open(LKF_PATH, "w", encoding="utf-8") as f:
        f.write(lkf_text)

    print(f"[{MODE.upper()}] Generated new LKF file: {LKF_PATH}")
    for f in object_files:
        print("  ", f)

if __name__ == "__main__":
    main()