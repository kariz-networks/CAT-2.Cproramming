/*
NAME: jseph kariuki gichuhi
REG:CT100/G/25126/25
Description:gross pay
*/

int main() {
    float h, w, g, t, n; // h=hours, w=wage, g=gross, t=tax, n=net

    printf("Hours: "); scanf("%f", &h);
    printf("Wage: $"); scanf("%f", &w);

    // 2. Gross Pay 
    if (h > 40) {
        g = (40 * w) + ((h - 40) * w * 1.5);
    } else {
        g = h * w;
    }

    // 3. Tax 
    if (g <= 600) {
        t = g * 0.15; // 15% rate
    } else {
        t = (600 * 0.15) + ((g - 600) * 0.20);
    }
    n = g - t;

    // 5. Output
    printf("\nGross: $%.2f\n", g);
    printf("Taxes: $%.2f\n", t);
    
    
    return 0;
}