#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int l;
        int sum = 0;
        int curr;
        scanf("%d", &l);

        for(int i=0; i<l; i++) {
            scanf("%d", &curr);
            if(curr % 2 == 1) {
                sum ^= (curr + 1);
            } else sum ^= (curr - 1);
        }
        printf("%c\n", sum == 0? 'L':'W');
    }
}
