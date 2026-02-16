#!/bin/bash

# Terminal Push_swap Visualizer - No dependencies needed!
# Usage: ./terminal_viz.sh <numbers>

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
NC='\033[0m' # No Color
BOLD='\033[1m'

# Configuration
DELAY=0.1  # Seconds between operations (adjust for speed)
BAR_WIDTH=50

if [ $# -eq 0 ]; then
    echo "Usage: $0 <numbers>"
    echo "Example: $0 4 67 3 87 23"
    exit 1
fi

# Get numbers
NUMBERS="$@"

# Run push_swap and get operations
OPS=$(./push_swap $NUMBERS 2>/dev/null)
if [ -z "$OPS" ]; then
    echo "Error: push_swap produced no output"
    echo "Make sure ./push_swap exists and works"
    exit 1
fi

# Initialize stacks
STACK_A=($NUMBERS)
STACK_B=()

# Get min and max for normalization
MIN=${STACK_A[0]}
MAX=${STACK_A[0]}
for num in "${STACK_A[@]}"; do
    [ $num -lt $MIN ] && MIN=$num
    [ $num -gt $MAX ] && MAX=$num
done
RANGE=$((MAX - MIN))
[ $RANGE -eq 0 ] && RANGE=1

# Function to draw a bar
draw_bar() {
    local value=$1
    local normalized=$(( (value - MIN) * BAR_WIDTH / RANGE ))
    [ $normalized -lt 1 ] && normalized=1
    
    printf "${CYAN}"
    for ((i=0; i<normalized; i++)); do
        printf "█"
    done
    printf "${NC}"
}

# Function to display stacks
display_stacks() {
    local operation=$1
    local count=$2
    
    clear
    echo -e "${BOLD}${YELLOW}╔════════════════════════════════════════════════════════╗${NC}"
    echo -e "${BOLD}${YELLOW}║          PUSH_SWAP TERMINAL VISUALIZER                 ║${NC}"
    echo -e "${BOLD}${YELLOW}╚════════════════════════════════════════════════════════╝${NC}"
    echo ""
    
    if [ -n "$operation" ]; then
        echo -e "Operation: ${RED}${BOLD}$operation${NC} | Count: ${YELLOW}$count${NC}"
    fi
    echo ""
    
    # Display Stack A (limit display for large stacks)
    echo -e "${GREEN}${BOLD}Stack A (${#STACK_A[@]} elements):${NC}"
    if [ ${#STACK_A[@]} -eq 0 ]; then
        echo -e "  ${MAGENTA}[empty]${NC}"
    else
        local display_count=${#STACK_A[@]}
        [ $display_count -gt 20 ] && display_count=20
        for ((i=0; i<display_count; i++)); do
            printf "  %4d │ " "${STACK_A[$i]}"
            draw_bar "${STACK_A[$i]}"
            echo ""
        done
        [ ${#STACK_A[@]} -gt 20 ] && echo -e "  ${MAGENTA}... (${#STACK_A[@]} total)${NC}"
    fi
    
    echo ""
    echo -e "${BLUE}${BOLD}Stack B (${#STACK_B[@]} elements):${NC}"
    if [ ${#STACK_B[@]} -eq 0 ]; then
        echo -e "  ${MAGENTA}[empty]${NC}"
    else
        local display_count=${#STACK_B[@]}
        [ $display_count -gt 20 ] && display_count=20
        for ((i=0; i<display_count; i++)); do
            printf "  %4d │ " "${STACK_B[$i]}"
            draw_bar "${STACK_B[$i]}"
            echo ""
        done
        [ ${#STACK_B[@]} -gt 20 ] && echo -e "  ${MAGENTA}... (${#STACK_B[@]} total)${NC}"
    fi
    
    echo ""
    echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

# Show initial state
display_stacks "" 0
sleep 0.5

# Execute operations
op_count=0
while IFS= read -r op; do
    ((op_count++))
    
    case $op in
        sa)
            if [ ${#STACK_A[@]} -ge 2 ]; then
                temp=${STACK_A[0]}
                STACK_A[0]=${STACK_A[1]}
                STACK_A[1]=$temp
            fi
            ;;
        sb)
            if [ ${#STACK_B[@]} -ge 2 ]; then
                temp=${STACK_B[0]}
                STACK_B[0]=${STACK_B[1]}
                STACK_B[1]=$temp
            fi
            ;;
        ss)
            if [ ${#STACK_A[@]} -ge 2 ]; then
                temp=${STACK_A[0]}
                STACK_A[0]=${STACK_A[1]}
                STACK_A[1]=$temp
            fi
            if [ ${#STACK_B[@]} -ge 2 ]; then
                temp=${STACK_B[0]}
                STACK_B[0]=${STACK_B[1]}
                STACK_B[1]=$temp
            fi
            ;;
        pa)
            if [ ${#STACK_B[@]} -gt 0 ]; then
                STACK_A=(${STACK_B[0]} ${STACK_A[@]})
                STACK_B=("${STACK_B[@]:1}")
            fi
            ;;
        pb)
            if [ ${#STACK_A[@]} -gt 0 ]; then
                STACK_B=(${STACK_A[0]} ${STACK_B[@]})
                STACK_A=("${STACK_A[@]:1}")
            fi
            ;;
        ra)
            if [ ${#STACK_A[@]} -gt 0 ]; then
                first=${STACK_A[0]}
                STACK_A=("${STACK_A[@]:1}" $first)
            fi
            ;;
        rb)
            if [ ${#STACK_B[@]} -gt 0 ]; then
                first=${STACK_B[0]}
                STACK_B=("${STACK_B[@]:1}" $first)
            fi
            ;;
        rr)
            if [ ${#STACK_A[@]} -gt 0 ]; then
                first=${STACK_A[0]}
                STACK_A=("${STACK_A[@]:1}" $first)
            fi
            if [ ${#STACK_B[@]} -gt 0 ]; then
                first=${STACK_B[0]}
                STACK_B=("${STACK_B[@]:1}" $first)
            fi
            ;;
        rra)
            if [ ${#STACK_A[@]} -gt 0 ]; then
                last=${STACK_A[-1]}
                STACK_A=($last "${STACK_A[@]:0:${#STACK_A[@]}-1}")
            fi
            ;;
        rrb)
            if [ ${#STACK_B[@]} -gt 0 ]; then
                last=${STACK_B[-1]}
                STACK_B=($last "${STACK_B[@]:0:${#STACK_B[@]}-1}")
            fi
            ;;
        rrr)
            if [ ${#STACK_A[@]} -gt 0 ]; then
                last=${STACK_A[-1]}
                STACK_A=($last "${STACK_A[@]:0:${#STACK_A[@]}-1}")
            fi
            if [ ${#STACK_B[@]} -gt 0 ]; then
                last=${STACK_B[-1]}
                STACK_B=($last "${STACK_B[@]:0:${#STACK_B[@]}-1}")
            fi
            ;;
    esac
    
    display_stacks "$op" "$op_count"
    sleep $DELAY
done <<< "$OPS"

# Final display
echo ""
echo -e "${GREEN}${BOLD}╔════════════════════════════════════════════════════════╗${NC}"
echo -e "${GREEN}${BOLD}║              ✓ SORTING COMPLETE!                       ║${NC}"
echo -e "${GREEN}${BOLD}╚════════════════════════════════════════════════════════╝${NC}"
echo ""
echo -e "Total operations: ${YELLOW}${BOLD}$op_count${NC}"
echo ""
