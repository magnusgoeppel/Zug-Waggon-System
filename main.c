#include <stdio.h>

int main()
{
    double ZTpunkte = 0;
    double ATpunkte = 0;
    double UEpunkte = 0;
    double ALLpunkte = 0;
    double punkte = 0;
    double ZTundAT = 0;
    double ZTundATprodz = 0;
    double GESpunkte = 0;
    double GESprodz = 0;
    char typ;
    int abschlusstest = 0;

    while (typ != '=')
    {
        printf("\nZT Punkte: %.2lf\n", ZTpunkte);
        printf("AT Punkte: %.2lf\n", ATpunkte);
        printf("UE Punkte: %.2lf\n", UEpunkte);
        printf("Erreichbare Gesamtpunkte: %.2f\n", ALLpunkte);

        printf("Typ: ");
        scanf(" %c", &typ);

        switch (typ)
        {
            case 'z':
                printf("\nPunkte: ");
                scanf(" %lf", &punkte);

                if (punkte >= 0 && punkte <= 10)
                {
                    ZTpunkte += punkte;
                    ALLpunkte += 10;
                }

                else
                {
                    printf("\nungueltiger Bereich: min 0.00, max 10.00");
                }
                break;

            case 'a':
                if (abschlusstest == 0)
                {
                    printf("\nPunkte: ");
                    scanf("%lf", &punkte);

                    if (punkte >= 0 && punkte <= 70)
                    {
                        ATpunkte += punkte;
                        ALLpunkte += 70;
                        ++abschlusstest;
                    }

                    else
                    {
                        printf("\nungueltiger Bereich: min 0.00, max 70.00");
                    }
                }

                else
                {
                    printf("\nnur ein Abschlusstest erlaubt");
                }
                break;

            case 'u':
                printf("\nPunkte: ");
                scanf(" %lf", &punkte);
                if (punkte >= 0 && punkte <= 0.5)
                {
                    UEpunkte += punkte;

                    if (UEpunkte > 10)
                    {
                        UEpunkte = 10;
                    }
                }

                else
                {
                    printf("\nungueltiger Bereich: min 0.00, max 0.50");
                }
                break;

            case '=':
                ZTundAT = ZTpunkte + ATpunkte;
                ZTundATprodz = ZTundAT/ALLpunkte*100;

                GESpunkte = ZTundAT + UEpunkte;
                GESprodz = GESpunkte/ALLpunkte*100;

                if (GESpunkte == 0 || ZTundAT == 0)
                {
                    printf("\nGesamtpunkte absolut: 0.00");
                    printf("\nGesamtpunkte %%: 0.00 %%");
                    printf("\nNote: 0");
                }
                else if (ZTundATprodz < 55)
                {
                    printf("\nGesamtpunkte absolut: %.2lf", ZTundAT);
                    printf("\nGesamtpunkte %%: %.2lf %%", ZTundATprodz);
                    printf("\nNote: 5");
                }
                else if (GESprodz < 67)
                {
                    printf("\nGesamtpunkte absolut: %.2lf", GESpunkte);
                    printf("\nGesamtpunkte %%: %.2lf %%", GESprodz);
                    printf("\nNote: 4");
                }

                else if (GESprodz < 78)
                {
                    printf("\nGesamtpunkte absolut: %.2lf", GESpunkte);
                    printf("\nGesamtpunkte %%: %.2lf %%", GESprodz);
                    printf("\nNote: 3");
                }

                else if (GESprodz < 89)
                {
                    printf("\nGesamtpunkte absolut: %.2lf", GESpunkte);
                    printf("\nGesamtpunkte %%: %.2lf %%", GESprodz);
                    printf("\nNote: 2");
                }

                else if (GESprodz >= 89)
                {
                    printf("\nGesamtpunkte absolut: %.2lf", GESpunkte);
                    printf("\nGesamtpunkte %%: %.2lf %%", GESprodz);
                    printf("\nNote: 1");
                }
                break;

            default:
                printf("\nungueltige Eingabe");
                break;
        }
    }
    return 0;
}

