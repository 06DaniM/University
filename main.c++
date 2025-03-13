#include "raylib.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define BULLET_SPEED 7
#define PLAYER_SPEED 5.0f

enum PowerUpType {
    Double_shot,
    Shield
};

struct PowerUp {
    Rectangle rect;
    bool active;
    PowerUpType type; // Tipo de power-up
};

typedef struct Bullet {
    Rectangle rect;
    bool active;
} Bullet;

typedef struct Enemy {
    Rectangle rect;
    bool active;
    bool isAttacking;
    float attackTime;
    float attackCooldown;
    Vector2 targetPosition1; // Loop position
    Vector2 targetFinalPosition; // Final position
    float targetIdlePosition; // Idle position
    float entryTime; // Tiempo de entrada
    int index; // Índice del enemigo en la fila
    int loopDirection;
    bool enemyInitialState;
    bool enemyLoopState;
    bool manual;
    bool idle;
    bool random;
} Enemy;

typedef struct Bullet_Enemy {
    Rectangle rect;
    bool active;
} Bullet_Enemy;

const int screenWidth = 1920;
const int screenHeight = 1080;
int screen = 1;

int maxEnemies = 5;
int currentEnemies = 0;

std::vector<Bullet> bullets;
std::vector<Bullet_Enemy> enemyBullets;

void UpdateEnemy(std::vector<Bullet_Enemy>& enemyBullets, Enemy& enemy, float deltaTime);
void SpawnEnemies(std::vector<Enemy>& enemies, float baseHeight, float baseWidth, int direction, float targetx, float targety);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Space Attacks!");

    Rectangle player = { (screenWidth - 74) / 2.0f, screenHeight / 1.5f, 64, 64 };

    std::vector<Enemy> enemies;
    std::vector<PowerUp> powerUps; // Vector to manage the generated power ups 


    int currentWave = 1;
    int totalWaves = 3;  // Number of waves per screen
    float waveTimer = 0.0f;
    float waveDelay = 10.0f; // Seconds between waves

    // Generate the first wave & positions
    SpawnEnemies(enemies, 100.0f, -100.0f, 1, screenWidth / 1.5f, screenHeight / 2.5f); // Wave 1

    Texture2D shipSpriteBase = LoadTexture("resources/ship/Nave Base.png");
    Texture2D shipSpriteDouble = LoadTexture("resources/ship/NAVE 2DS 64X64.png");
    Texture2D shipSpriteBuble = LoadTexture("resources/ship/Nave Bubble 0.png");
    Texture2D shipSpriteDoubleandBuble = LoadTexture("resources/ship/Nave 2S Bubble 0.png");

    Texture2D enemySprite = LoadTexture("resources/enemies/nave draconoida.png");

    Texture2D doubleShotSprite = LoadTexture("resources/powerUps/DobleShot_PowerUp.png");
    Texture2D shieldSprite = LoadTexture("resources/powerUps/Shield_PowerUp.png");

    Texture2D bulletSprite = LoadTexture("resources/bullets/Disparo_Spaceship.png");
    Texture2D bulletEnemySprite = LoadTexture("resources/bullets/Disparo_Regular_Enemy.png");
    Texture2D bulletBossSprite = LoadTexture("resources/bullets/Disparo_Boss.png");

    Texture2D background = LoadTexture("resources/backgrounds/FONDO_GALAGA.png");

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    bool doubleShot = false, shield = false, canAct = false;
    bool pause = false, gameOver = false, hasWon = false;
    bool inMenu = true;
    int score = 0;
    int life = 3;
    float scale = 0.75f; // Reduce a 50% the scale of the sprites

    float shotCooldown = 0.3f;  // Time between shots
    float shotTimer = 0.0f;     // Timer for counting seconds
    bool showGameOver = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // For testing
        if (IsKeyPressed(KEY_R))
        {
            doubleShot = !doubleShot;
        }

        if (IsKeyPressed(KEY_F))
        {
            shield = !shield;
        }

        if (IsKeyPressed(KEY_ENTER)) // Change to when life is <= 0
        {
            life -= 1;
        }

        if (IsKeyPressed(KEY_BACKSPACE)) // Change to when life is <= 0
        {
            hasWon = true;
        }

        // Pause the game
        if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed('P')) {
            pause = !pause;
            canAct = !canAct;
        }

        // Menu manager
        if (inMenu)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(background, 0, 0, WHITE); // Draw the background

            DrawTextEx(font, "SCORE", { 50, 15 }, 34, 2, WHITE);
            DrawTextEx(font, "0", { 50, 40 }, 34, 2, WHITE);

            int textWidth = MeasureText("Press any key to start", 20); // Measure the length of the text
            DrawText("Press any key to start", (screenWidth - textWidth) / 2, screenHeight / 2, 20, WHITE); // Center the text
            EndDrawing();

            if (GetKeyPressed() != 0) // Detect any key
            {
                life = 3;
                inMenu = false;
                canAct = true;
            }
            continue; // Avoid the code is still executing in the menu
        }

        // Game manager 
        if (!pause)
        {
            // Movement of the ship
            if (IsKeyDown(KEY_D) && canAct) player.x += PLAYER_SPEED;
            if (IsKeyDown(KEY_A) && canAct) player.x -= PLAYER_SPEED;

            // Limit the movemente inside the window
            if (player.x < 0) player.x = 0;
            if (player.x > screenWidth - player.width) player.x = screenWidth - player.width;

            // Shots with cooldown
            shotTimer += GetFrameTime();
            if ((IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT)) && shotTimer >= shotCooldown && canAct)
            {
                shotTimer = 0.0f;

                // Define the size of the bullets collision
                float bulletWidth = 16;  // Width of the collision
                float bulletHeight = 12; // Height of the collision

                if (doubleShot)
                {
                    bullets.push_back({ { player.x + player.width / 2 - 15, player.y + player.height / 2, bulletWidth, bulletHeight }, true });
                    bullets.push_back({ { player.x + player.width / 2 + 15, player.y + player.height / 2, bulletWidth, bulletHeight }, true });
                }

                else
                {
                    bullets.push_back({ { player.x + player.width / 2, player.y, bulletWidth, bulletHeight }, true });
                }
            }


            // Update the bullets
            for (Bullet& bullet : bullets)
            {
                if (bullet.active)
                {
                    bullet.rect.y -= BULLET_SPEED;

                    for (Enemy& enemy : enemies)
                    {
                        if (enemy.active)
                        {
                            if (CheckCollisionRecs(bullet.rect, enemy.rect)) // Si hay colisión con un enemigo
                            {
                                bullet.active = false;
                                enemy.active = false;
                                score += 100;
                                currentEnemies--;

                                // 20% to generate the item/object
                                if (GetRandomValue(1, 100) < 20) // 20% de probabilidad de generar un power-up
                                {
                                    // Lista de power-ups disponibles según los estados actuales y los que ya están en pantalla
                                    std::vector<PowerUpType> availablePowerUps;

                                    PowerUp newPowerUp;

                                    bool doubleShotOnScreen = false;
                                    bool shieldOnScreen = false;

                                    // Verificar si ya hay un power-up de cada tipo en pantalla
                                    for (const auto& powerUp : powerUps)
                                    {
                                        if (powerUp.type == Double_shot) doubleShotOnScreen = true;
                                        if (powerUp.type == Shield) shieldOnScreen = true;
                                    }

                                    // Solo añadir si el power-up no está activo ni en pantalla
                                    if (!doubleShot && !doubleShotOnScreen) availablePowerUps.push_back(Double_shot);
                                    if (!shield && !shieldOnScreen) availablePowerUps.push_back(Shield);

                                    // Solo generamos un power-up si hay disponibles
                                    if (!availablePowerUps.empty())
                                    {
                                        newPowerUp.rect = { enemy.rect.x + enemy.rect.width / 2, enemy.rect.y + enemy.rect.height / 2, 20, 20 };

                                        // Convertir size_t a int de forma segura
                                        int maxIndex = static_cast<int>(availablePowerUps.size()) - 1;
                                        newPowerUp.type = availablePowerUps[GetRandomValue(0, maxIndex)];

                                        powerUps.push_back(newPowerUp);
                                    }
                                    newPowerUp.active = true;
                                }

                                break;
                            }
                        }
                    }
                }
            }

            // Delete the inactive bullets
            bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                [](const Bullet& b) { return !b.active || b.rect.y < 0; }), bullets.end());

            // Update the enemeis
            for (Enemy& enemy : enemies)
            {
                if (enemy.active)
                {
                    UpdateEnemy(enemyBullets, enemy, GetFrameTime());
                }
            }

            // Update enemies bullets
            for (Bullet_Enemy& bullet : enemyBullets)
            {
                if (bullet.active)
                {
                    bullet.rect.y += BULLET_SPEED;
                    if (CheckCollisionRecs(player, bullet.rect) && !shield)
                    {
                        bullet.active = false;
                        life--;
                        break;
                    }

                    else if (CheckCollisionRecs(player, bullet.rect) && shield)
                    {
                        shield = false;
                        bullet.active = false;
                        break;
                    }
                }
            }

            // Delete the inactive bullets
            enemyBullets.erase(std::remove_if(enemyBullets.begin(), enemyBullets.end(),
                [](const Bullet_Enemy& b) { return !b.active || b.rect.y < 0; }), enemyBullets.end());

            // === WAVES ===
            if (currentWave < totalWaves)
            {
                if (currentEnemies == 0 && currentWave == 1)
                {
                    currentWave++;
                    SpawnEnemies(enemies, 150.0f, screenWidth + 100, -1, 0.0f, 0.0f); // Wave 2
                }

                if (currentEnemies == 0 && currentWave == 2)
                {
                    currentWave++;
                    SpawnEnemies(enemies, 150.0f, screenWidth + 100, -1, 0.0f, 0.0f); // Wave 3
                }
            }

            else if (currentEnemies == 0 && currentWave >= 3)
            {
                hasWon = true;
            }

            for (PowerUp& powerUp : powerUps)
            {
                if (powerUp.active)
                {
                    powerUp.rect.y += 2; // Velocity to down

                    // Activate the double shot if collsion between the ship and the item
                    if (CheckCollisionRecs(player, powerUp.rect))
                    {
                        if (powerUp.type == Double_shot)
                        {
                            doubleShot = true;
                        }

                        else if (powerUp.type == Shield)
                        {
                            shield = true;
                        }

                        powerUp.active = false; // Desactivate the power up
                    }
                }
            }

            // Eliminar power-ups inactivos
            powerUps.erase(std::remove_if(powerUps.begin(), powerUps.end(),
                [](const PowerUp& p) { return !p.active || p.rect.y > screenHeight; }), powerUps.end());
        }

        // Game Over when is dead
        if (life <= 0)
        {
            gameOver = true;
        }

        // Draw all the scene
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        // Draw the bullets
        for (const Bullet& bullet : bullets)
        {
            if (bullet.active)
            {
                DrawTexture(bulletSprite,
                    (int)(bullet.rect.x + bullet.rect.width / 2 - bulletSprite.width / 2),
                    (int)(bullet.rect.y + bullet.rect.height / 2 - bulletSprite.height / 2),
                    WHITE);
            }
        }

        // Draw the enemy bullets
        for (const Bullet_Enemy& bullet : enemyBullets)
        {
            if (bullet.active)
            {
                DrawTexture(bulletEnemySprite,
                    (int)(bullet.rect.x + bullet.rect.width / 2 - bulletSprite.width / 2),
                    (int)(bullet.rect.y + bullet.rect.height / 2 - bulletSprite.height / 2),
                    WHITE);
            }
        }

        // Draw the ship
        if (doubleShot && !shield)
        {
            DrawTexture(shipSpriteDouble, (int)player.x, (int)player.y, WHITE);
        }

        else if (shield && !doubleShot)
        {
            DrawTexture(shipSpriteBuble, (int)player.x, (int)player.y, WHITE);
        }

        else if (doubleShot && shield)
        {
            DrawTexture(shipSpriteDoubleandBuble, (int)player.x, (int)player.y, WHITE);
        }

        else
        {
            DrawTexture(shipSpriteBase, (int)player.x, (int)player.y, WHITE);
        }

        // Draw the lifes of the ship
        for (int i = 0; i < life; i++) {
            Vector2 position = { 75 + i * (shipSpriteBase.width * scale + 10), screenHeight - shipSpriteBase.height * scale - 75 };
            DrawTextureEx(shipSpriteBase, position, 0.0f, scale, WHITE);
        }

        // Draw the enemies
        for (const Enemy& enemy : enemies)
        {
            if (enemy.active)
            {
                Vector2 position = { (enemy.rect.x + enemy.rect.width / 2 - enemySprite.width / 2),
                    (enemy.rect.y + enemy.rect.height / 2 - enemySprite.height / 2) };

                DrawTextureEx(enemySprite, position, 0.0f, 1.0f, WHITE);
            }
        }

        // Display the score
        DrawTextEx(font, TextFormat("SCORE: %i", score), { 10, 10 }, 34, 2, WHITE);

        // Display wave and enemy count
        DrawTextEx(font, TextFormat("Wave %i / %i", currentWave, totalWaves), { screenWidth - 200, 10 }, 34, 2, WHITE); // Quitar cuando esté acabado el manager

        // Draw pause
        if (pause)
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, { 0,0,0,125 });
            DrawTextEx(font, "PAUSE", { (screenWidth - 100) / 2, (screenHeight - 50) / 2 }, 50, 2, WHITE);
        }

        // Game Over manager
        if (gameOver)
        {
            // Show the GAME OVER screen
            BeginDrawing();
            ClearBackground(BLACK);

            int gameOverWidth = MeasureText("GAME OVER", 40);
            DrawText("GAME OVER", (screenWidth - gameOverWidth) / 2, screenHeight / 2, 40, RED);

            int retryWidth = MeasureText("Press any key to return to the menu", 20);
            DrawText("Press any key to return to the menu", (screenWidth - retryWidth) / 2, screenHeight / 2 + 50, 20, WHITE);

            EndDrawing();

            canAct = false;

            if (GetKeyPressed() != 0) // Detect any key
            {
                // Restart the game
                inMenu = true;
                gameOver = false;

                // Restore to its initial state
                player.x = (screenWidth - player.width) / 2.0f;
                bullets.clear();
                score = 0;
                currentWave = 1;
                SpawnEnemies(enemies, 100.0f, -50.0f, 1, 0.0f, 0.0f);
            }
            continue; // Avoid the code is still executing in the menu
        }

        if (hasWon)
        {
            // Show victory screen
            DrawRectangle(0, 0, screenWidth, screenHeight, { 0,0,0,125 });

            int winMessageWidth = MeasureText("CONGRATULATIONS, YOU WON", 20);
            int winMessageHeight = 20;

            int x = (screenWidth - winMessageWidth) / 2;
            int y = (screenHeight - winMessageHeight) / 2;

            // Show victory messages
            DrawText("CONGRATULATIONS, YOU WON", x, y, 20, WHITE);

            int retryWidth = MeasureText("Press any key to return to the menu", 20);
            DrawText("Press any key to return to the menu", (screenWidth - retryWidth) / 2, screenHeight / 2 + 50, 20, WHITE);

            EndDrawing();

            canAct = false;

            if (GetKeyPressed() != 0) // Detect any key
            {
                // Reset the initial states
                hasWon = false;  // Reset the variable
                inMenu = true;   // Return to menu
                score = 0;       // Reset the score
                life = 3;        // Reset the life
                currentWave = 1; // Reset the waves

                // Reset the position of the player
                player.x = (screenWidth - player.width) / 2.0f;

                // Clear all the enemies and bullets, just in case
                bullets.clear();
                enemies.clear();
                currentEnemies = 0;
            }
            continue; // Avoid the code is still executing in the victory menu
        }

        for (const PowerUp& powerUp : powerUps)
        {
            if (powerUp.active && powerUp.type == Double_shot)
            {
                DrawTexture(doubleShotSprite, (int)powerUp.rect.x, (int)powerUp.rect.y, WHITE); // Draw the double shot item
            }

            else if (powerUp.active && powerUp.type == Shield)
            {
                DrawTexture(shieldSprite, (int)powerUp.rect.x, (int)powerUp.rect.y, WHITE); // Cambiar al sprite del escudo cuando esté hecho
            }
        }

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(shipSpriteBase);
    UnloadTexture(shipSpriteDouble);
    UnloadTexture(enemySprite);
    UnloadTexture(bulletSprite);
    UnloadTexture(background);
    UnloadFont(font);

    CloseWindow();
    return 0;
}

// Function to spawn enemies in a wave
void SpawnEnemies(std::vector<Enemy>& enemies, float baseHeight, float baseWidth, int direction, float targetx, float targety)
{
    enemies.clear();
    for (int i = 0; i < maxEnemies; i++) {
        float delay = i * 0.35f; // Space between enemies
        float startX = baseWidth; // Position X in the wave
        float startY = baseHeight; // Position Y in the wave
        float targetX = targetx; // Loop X position
        float targetY = targety; // Loop Y position
        float idletargetX = screenWidth / 6.0f * (i + 0.75f) - 200;
        float finaltargetX = screenWidth / 6.0f * (i + 0.75f); // Final X position
        float finaltargetY = baseHeight + 20.0f; // Final Y position

        // Enemy data
        enemies.push_back({ { startX, startY, 112, 84 }, true, false, 3.0f, // Enemys collision
                            (float)GetRandomValue(2, 5), { targetX, targetY }, { finaltargetX, finaltargetY }, idletargetX,-delay, i, direction, true, false, true, false, false });
    }
    currentEnemies = maxEnemies; // Change to sum when more waves will be added
}

float Lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

void UpdateEnemy(std::vector<Bullet_Enemy>& enemyBullets, Enemy& enemy, float deltaTime)
{
    float midX = screenWidth / 2.0f;
    float midY = enemy.rect.y;

    enemy.entryTime += deltaTime;

    // === NEW ENEMY MOVEMENT ===

    // El retraso se calcula dependiendo del índice del enemigo
    float delayTime = 0.0f; // Por ejemplo, 0.5 segundos de retraso por cada enemigo

    // Enemy start de movement with a delay 

    if (enemy.entryTime >= delayTime)
    {
        // === NEW ENEMY MOVEMENT ===

        // Calcular la posición circular
        float radius = 150.0f;  // Radio del círculo
        float centerX = enemy.targetPosition1.x; // Centro de la órbita
        float centerY = enemy.targetPosition1.y + radius;

        if (enemy.manual)
        {

            // Incrementar 't' para el movimiento circular
            float velocity = 500.0f; // Velocidad de movimiento
            float moveSpeed = velocity * deltaTime;
            // === 1ST OBJECTIVE ===
            if (enemy.enemyInitialState)
            {
                // Calcular la distancia entre la posición actual y el objetivo
                float distX = enemy.targetPosition1.x - enemy.rect.x;
                float distY = enemy.targetPosition1.y - enemy.rect.y;

                float distance = sqrt(distX * distX + distY * distY); // Distancia total al objetivo

                enemy.enemyLoopState = false;
                if (distance > moveSpeed)
                {
                    // Normalizar la dirección
                    float directionX = distX / distance;
                    float directionY = distY / distance;

                    // Mover al enemigo hacia el objetivo
                    enemy.rect.x += directionX * moveSpeed;
                    enemy.rect.y += directionY * moveSpeed;
                }

                else
                {
                    enemy.enemyInitialState = false;
                    enemy.enemyLoopState = true;
                }
            }

            // CORREGIR PUNTO DE INICIO DEL LOOP

            // === LOOP MOVEMENT ===
            else if (!enemy.enemyInitialState && enemy.enemyLoopState)
            {
                float t = enemy.entryTime;
                float loopT = t * 0.5f;  // Controlar la velocidad angular (ajusta este valor si es necesario)

                enemy.rect.x -= cos(loopT * PI * 2) * 5; // Movimiento en X
                enemy.rect.y -= sin(loopT * PI * 2) * 5; // Movimiento en Y

                if (enemy.entryTime > 4 + .5f)
                {
                    enemy.enemyLoopState = false;
                    cout << enemy.enemyLoopState;
                }
            }

            // === FINAL STATE ==
            else if (!enemy.enemyInitialState && !enemy.enemyLoopState)
            {
                float distX = enemy.targetFinalPosition.x - enemy.rect.x;
                float distY = enemy.targetFinalPosition.y - enemy.rect.y;

                float distance = sqrt(distX * distX + distY * distY); // Distancia total al objetivo

                if (distance > moveSpeed)
                {
                    // Normalizar la dirección
                    float directionX = distX / distance;
                    float directionY = distY / distance;

                    // Mover al enemigo hacia el objetivo
                    enemy.rect.x += directionX * moveSpeed;
                    enemy.rect.y += directionY * moveSpeed;
                }

                else
                {
                    enemy.rect.x = enemy.targetFinalPosition.x;
                    enemy.rect.y = enemy.targetFinalPosition.y;

                    enemy.manual = false;
                    enemy.idle = true;
                }
            }
        }

        // === RANDOM STATE
        
        else if (enemy.idle && !enemy.random)
        {
            // Incrementar 't' para el movimiento circular
            float velocity = 200.0f; // Velocidad de movimiento
            float moveSpeed = velocity * deltaTime;

            float distX = enemy.targetIdlePosition - enemy.rect.x;

            float distance = sqrt(distX * distX); // Distancia total al objetivo

            if (distance > moveSpeed)
            {
                // Normalizar la dirección
                float directionX = distX / distance;

                // Mover al enemigo hacia el objetivo
                enemy.rect.x += directionX * moveSpeed;
            }

            else
            {
                enemy.rect.x = enemy.targetFinalPosition.x;
            }
        }

        else if (enemy.random)
        {

        }
    }

    // Lógica de disparo
    if (enemy.attackCooldown >= 1.5f) // Si está listo para atacar
    {
        enemyBullets.push_back({ { enemy.rect.x + enemy.rect.width / 2, enemy.rect.y + enemy.rect.height / 2, 16, 12 }, true });
        enemy.attackCooldown = 0.0f; // Resetear el cooldown
    }

    else
    {
        enemy.attackCooldown += deltaTime;  // Reducir el tiempo de cooldown
    }
}
