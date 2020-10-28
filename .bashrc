# Interactive Check
[[ $- != *i* ]] && return

# Alaises
alias .='cd ..'
alias ..='cd ../..'
alias grep='grep --color=auto'
alias ls='ls -ahl --color=auto'

# Prompt
export PS1="\[\e[31m\]\A\[\e[m\]\[\e[31m\]>\[\e[m\] "

# History
set +o history

# Exports
export EDITOR=nvim

# LS after CD
function cd {
builtin cd "$@" && ls -F
}
