cmake_minimum_required(VERSION 3.16)
project(CS236)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

include_directories(.)

add_executable(CS236
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        Q_MarkAutomaton.cpp
        Q_MarkAutomaton.h
        Left_ParenAutomaton.cpp
        Left_ParenAutomaton.h
        Right_ParenAutomaton.cpp
        Right_ParenAutomaton.h
        EndOFAutomaton.cpp
        EndOFAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        UndefinedAutomaton.cpp
        UndefinedAutomaton.h
        Parser.cpp
        Parser.h
        DatalogProgram.cpp
        DatalogProgram.h
        Rule.cpp
        Rule.h
        Predicate.cpp
        Predicate.h
        Parameter.cpp
        Parameter.h)
