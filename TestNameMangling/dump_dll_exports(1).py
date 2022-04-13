# coding: utf-8

import sys

import pefile

try:
    import cppmangle
    cppmangle_available = True
except ImportError:
    cppmangle_available = False


def demangle(symbol: str) -> str:
    if cppmangle_available:
        return cppmangle.cdecl_sym(cppmangle.demangle(symbol))
    else:
        return symbol


def main():
    if len(sys.argv) != 2:
        print('DLL path missing.')
        return

    pe = pefile.PE(sys.argv[1])
    try:
        export_dir_data = pe.DIRECTORY_ENTRY_EXPORT
    except AttributeError:
        print('DIRECTORY_ENTRY_EXPORT not found.')
        return

    symbols = export_dir_data.symbols
    mangled_symbols = [
        symbol.name.decode('ascii') for symbol in symbols if symbol.name
    ]

    if cppmangle_available:
        for symbol in mangled_symbols:
            try:
                print(symbol, '->', demangle(symbol))
            except:
                print(symbol)
    else:
        for symbol in mangled_symbols:
            print(symbol)


if __name__ == '__main__':
    main()

# References:
# ../cppmangle/dump_dll_exports.py
# ../parse/dump_dll_exports.py
