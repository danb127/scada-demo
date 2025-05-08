# Talent Portfolio 
- Status: 🟢 Planned | 🟡 In Progress | 🔴 Stalled  
- Deadline: [[YYYY-MM-DD]]  
- Related Notes:  

## NEXT STEPS  
- [ ]  Looked up examples like https://kazytauginas.com/
- [ ]  

## PROGRESS LOG  
- [[2025-01-30]]: Started project  
- 2025-02-05:
	- Looked up examples like https://kazytauginas.com/
	- Started project by first building installing Vite with React and initializing the project
	```zsh
	npm create vite@latest BakerDanielCompCard -- --template react
	cd BakerDanielCompCard
	npm install
	```
	- Then initialize Tailwind CSS
	```zsh
	npm install -D tailwindcss postcss autoprefixer @tailwind/postcss
	npx tailwindcss init -p
	```
 - [[2025-02-07]]: 
	 - Configure Tailwind CSS in `ailwind.config.js`
	 ```js
	/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./index.html",
    "./src/**/*.{js,jsx,ts,tsx}",
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}
	```
	- Add Tailwind CSS to `index.css`
  ```css
	@tailwind base;
	@tailwind components;
	@tailwind utilities;
```
- Fix `postcss.config.js` to include Tailwind CSS
```js
module.exports = {
  plugins: {
    '@tailwindcss/postcss': {},
    autoprefixer: {},
  },
}
```
- [[2025-02-09]]:
	- Had to re-add Tailwind css since my tailwind properties were not loading properly
	- According to https://tailwindcss.com/docs/installation/using-vite I had to run this to install Tailwind CSS with Vite via npm:
  
	```zsh
	npm install tailwindcss @tailwindcss/vite
	```
	- Then I had to edit my vite config by adding the Tailwind CSS plugin:
	```js
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
  plugins: [
    react(),
    tailwindcss(),
  ],
})
	```
	- Finally, I had to add the Tailwind CSS directives to my `index.css` file:
```css
 @import "tailwindcss";
``` 
- [[2025-02-10]]:
  - 
  - 
  - 