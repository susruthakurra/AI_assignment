## CAPTCHA Architecture

Idea :
Instead of using a simple static CAPTCHA image, this architecture introduces a dynamic CAPTCHA generation layer. 
The system generates unique challenges each time by combining random text generation, image distortion, 
and behavioral verification. This makes it harder for automated bots to predict or bypass the challenge.

Components :
1. User – The person attempting to access a service or submit a form.
2. Web Interface – Displays the CAPTCHA challenge and collects the user's response.
3. CAPTCHA Generator – Creates a random sequence of characters, numbers, or patterns for each request.
4. Distortion Engine – Applies visual noise, background patterns, rotations, and distortions to make
   automated recognition difficult.
5. Verification System – Compares the user’s input with the generated CAPTCHA solution.
6. CAPTCHA Database / Session Store – Temporarily stores the generated CAPTCHA and its correct value for verification.

Working :
1. When a user attempts to access a protected service, the system generates a CAPTCHA challenge.
2. The CAPTCHA Generator creates a random string or pattern.
3. The Distortion Engine converts it into a distorted image with noise and visual variations.
4. The CAPTCHA image is displayed to the user through the web interface.
5. The user enters the characters or solution they see in the image.
6. The Verification System checks the entered response with the stored value.
7. If the input matches, the user is verified as human; otherwise, a new CAPTCHA challenge is generated.

Architecture Flow :
User -> Web Interface -> CAPTCHA Generator -> Distortion Engine -> CAPTCHA Challenge (Image / Puzzle) -> User Response -> Verification System-> Decision Layer (Access granted if response is correct)
The dynamic CAPTCHA generation layer improves security by ensuring each challenge is unique.
By introducing distortions and randomization, the system prevents automated bots from easily solving the CAPTCHA
while still keeping it understandable for human users.
