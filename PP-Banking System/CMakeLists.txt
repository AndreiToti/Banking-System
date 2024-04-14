cmake_minimum_required(VERSION 3.27)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 main.c
        login.h
        iban.h
        meniu.h
        afisare.h
        register.h
        adauga_bani.h
        tranzactii.h
        edit.h
        after_log.h
)
