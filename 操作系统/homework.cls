%
% Choose template language
% preserve line 5 or 6 and comment the other
%
\def\hmwkLanguage{E}        % English template, but also supports Chinese in document body
 \def\hmwkLanguage{C}      % Chinese template, 取消本行注释，以使用中文模板（首页、页眉等）


%
% Use Page Header or not
%
\def\hmwkPageHeader{1}      % use page header
% \def\hmwkPageHeader{0}    % not use page header


%
% Use Cover Page or not
%
\def\hmwkCoverPage{1}       % use cover page
% \def\hmwkCoverPage{0}     % not use cover page


%
% based on article class
% 
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{homework}[2021/10/04 v1.0 homework Template]
\LoadClass{article} 


%
% necessary packages
%

\usepackage{fancyhdr}
\usepackage{extramarks}
\usepackage{amsmath}
\usepackage{amsthm}
\usepackage{amsfonts}
\usepackage{tikz}
\usepackage{algorithm}
\usepackage{algpseudocode}
\usepackage{enumerate}
\usepackage{listings}
\usepackage{xcolor}
\usepackage{cite}
\usepackage{graphicx}
\usepackage{bm}
\usepackage{ctex}
% \usepackage[osf]{libertineRoman}


\newcommand{\hmwkClassCN}{操作系统（2024-2025）}

%
% for graph visualization
%

\usetikzlibrary{automata,positioning}


%
% Basic Document Settings
%

\topmargin=-0.45in
\evensidemargin=0in
\oddsidemargin=0in
\textwidth=6.5in
\textheight=9.0in
\headsep=0.25in

\linespread{1.1}

\if \hmwkPageHeader 1
    \pagestyle{fancy}
    \if\hmwkLanguage E
        \lhead{\hmwkAuthorName}
        \chead{\hmwkClass: \hmwkTitle}
    \else
        \lhead{\hmwkAuthorNameCN (学号：\hmwkAuthorIDCN)}
        \chead{\hmwkClassCN: \hmwkTitleCN}
    \fi
    \if\hmwkLanguage E
        \author{\hmwkAuthorName}
    \else
        \author{\hmwkAuthorNameCN (学号：\hmwkAuthorIDCN)}
        
    \fi
    \rhead{\firstxmark}
    \lfoot{\lastxmark}
\fi
\cfoot{\thepage}

\renewcommand\headrulewidth{0.4pt}
\renewcommand\footrulewidth{0.4pt}

% \setlength\parindent{0pt}


%
% Create Problem Sections
%

\newcommand{\enterProblemHeader}[1]{
    \if\hmwkLanguage E
        \nobreak\extramarks{}{Problem \arabic{#1} continued on next page\ldots}\nobreak{}
        \nobreak\extramarks{Problem \arabic{#1} (continued)}{Problem \arabic{#1} continued on next page\ldots}\nobreak{}
    \else
        \nobreak\extramarks{}{问题 \arabic{#1} 下页继续}\nobreak{}
        \nobreak\extramarks{问题 \arabic{#1}}{问题 \arabic{#1}}\nobreak{}
    \fi
}

\newcommand{\exitProblemHeader}[1]{
    \if\hmwkLanguage E
        \nobreak\extramarks{Problem \arabic{#1} (continued)}{Problem \arabic{#1} continued on next page\ldots}\nobreak{}
        \stepcounter{#1}
        \nobreak\extramarks{Problem \arabic{#1}}{}\nobreak{}
    \else
        \nobreak\extramarks{问题 \arabic{#1}}{问题 \arabic{#1} 下页继续}\nobreak{}
        \stepcounter{#1}
        \nobreak\extramarks{问题 \arabic{#1}}{}\nobreak{}
    \fi
}

\setcounter{secnumdepth}{3}
\newcounter{partCounter}
\newcounter{homeworkProblemCounter}
\setcounter{homeworkProblemCounter}{1}
\if\hmwkLanguage E
    \nobreak\extramarks{Problem \arabic{homeworkProblemCounter}}{}\nobreak{}
\else
    \nobreak\extramarks{问题 \arabic{homeworkProblemCounter}}{}\nobreak{}
\fi

%
% Homework Problem Environment
%
% This environment takes an optional argument. When given, it will adjust the
% problem counter. This is useful for when the problems given for your
% assignment aren't sequential. See the last 3 problems of this template for an
% example.
%
\newenvironment{homeworkProblem}[1][-1]{
    \ifnum#1>0
        \setcounter{homeworkProblemCounter}{#1}
    \fi
    \vspace{0.2in}
    \if\hmwkLanguage E
        \section*{Problem \arabic{homeworkProblemCounter}}
    \else
        \section*{问题 \arabic{homeworkProblemCounter}}
    \fi
    \setcounter{partCounter}{1}
    \enterProblemHeader{homeworkProblemCounter}
}{
    \exitProblemHeader{homeworkProblemCounter}
}


% Alias for the Solution section header
\newcommand{\solution}[1][-1]{
    \ifnum#1>0
        \vspace{0.2in}
        \if\hmwkLanguage E
            \textbf{\large Solution of (#1)}
        \else
            \textbf{\large 解答 (#1)}
        \fi
        \vspace{0.1in}
    \else
        \vspace{0.2in}
        \if\hmwkLanguage E
            \textbf{\large Solution}
        \else
            \textbf{\large 解答}
        \fi
        \vspace{0.1in}
    \fi
}
\if\hmwkLanguage E
    \renewcommand{\proofname}{Proof}
    \renewcommand{\figurename}{Figure}
    \renewcommand{\tablename}{Table}
\fi