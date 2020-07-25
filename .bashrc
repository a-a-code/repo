# Interactive Check
[[ $- != *i* ]] && return

# Alaises
alias .='cd ..'
alias ..='cd ../..'
alias m='sudo mount'
alias grep='grep --color=auto'
alias ls='ls -ahl --color=auto'
alias work='cd ~/work/rumbl && mix phx.server'
alias dotfiles='/usr/bin/git --git-dir=/home/quiet/.dotfiles.git/ --work-tree=/home/quiet'
alias u='sudo pacman -Syu --noconfirm && sudo pacman -Scc --noconfirm && paccache -ruk0'

# Prompt
export PS1="\[\e[31m\]\A\[\e[m\]\[\e[31m\]>\[\e[m\] "

# History
set +o history

# Exports
export EDITOR=vim

# LS after CD
function cd {
builtin cd "$@" && ls -F
}
